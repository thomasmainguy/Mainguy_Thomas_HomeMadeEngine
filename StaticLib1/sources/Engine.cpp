#include <Engine.h>
#include <NullGraphic.h>
#include <NullAudio.h>
#include <NullInput.h>
#include <NullLog.h>
#include <NullTimer.h>
#include <NullScene.h>
#include <SDLGraphic.h>
#include <SDLInput.h>
#include <SceneManager.h>
#include <Timer.h>
#include <Log.h>
#include <SceneManager.h>
#include <ColliderManager.h>
#include <NullCollider.h>

#ifdef _WIN32
	#include <Windows.h> // visual studio
#endif

#define USE_SDL //pour utiliser la SDL pour le graphic m


bool thomas::Engine::Initialize(const std::string & aTitle, int aWidth, int aHeight)
{
	if (!m_IsInit)
	{
#ifdef USE_SDL
		m_GraphicService = new SDLGraphic();
		m_AudioService = new NullAudio();
		m_InputService = new SDLInput();
		m_TimerService = new Timer();
		m_LogService = new Log();
		m_SceneService = new SceneManager();
		m_ColliderService = new ColliderManager();
#else
		m_GraphicService = new NullGraphic();
		m_AudioService = new NullAudio();
		m_InputService = new NullInput();
		m_TimerService = new NullTimer();
		m_LogService = new NullLog();
		m_SceneService = new NullScene();
		m_ColliderService = new NullCollider();

#endif


		if (!m_GraphicService->Initialize())
		{
			m_LogService->LogUsingVS("Erreur Graphic \n");
			return false;
		}
		if (!m_AudioService->Initialize())
		{
			m_LogService->LogUsingVS("Erreur Audio \n");
			return false;
		}
		if (!m_InputService->Initialize())
		{
			m_LogService->LogUsingVS("Erreur Input \n");
			return false;
		}
		if (!m_TimerService->Initialize())
		{
			m_LogService->LogUsingVS("Erreur Timer \n");
			return false;
		}
		if (!m_SceneService->Initialize())
		{
			m_LogService->LogUsingVS("Erreur Scene \n");
			return false;
		}
		if (!m_GraphicService->InitWindow(aTitle, aWidth, aHeight))
		{
			m_LogService->LogUsingVS("Erreur Graphic Window \n");
			return false;
		}
		if (!m_ColliderService->Initialize())
		{
			m_LogService->LogUsingVS("Erreur Collider \n");
			return false;
		}
		//Create all manager here
		m_IsInit = true;
	}
	return m_IsInit;

}

void thomas::Engine::Start()
{
	if (m_IsInit && !m_IsRunning)
	{
		float tLastTime = m_TimerService->GetTime();
		m_IsRunning = true;
		while (m_IsRunning)
		{
			float start = m_TimerService->GetTime();
			float elapsed = start - tLastTime;

			ProcessInput();
			Update(elapsed * 0.001f);
			Render();

			tLastTime = start;
			m_TimerService->Wait(start + 16.6666f - m_TimerService->GetTime());
		}
		Clean();
	}
}

void thomas::Engine::ProcessInput()
{
}

void thomas::Engine::Stop()
{
	m_IsRunning = false;
	m_LogService->LogUsingVS("stop\n");
}

void thomas::Engine::Clean()
{
	//Delete all manager 
	SAFE_CLEAN(m_InputService);
	SAFE_CLEAN(m_AudioService);
	SAFE_CLEAN(m_GraphicService);
	SAFE_CLEAN(m_TimerService);
	SAFE_CLEAN(m_SceneService);
	SAFE_CLEAN(m_ColliderService);

	m_LogService->LogUsingVS("clean\n");

	SAFE_CLEAN(m_LogService); 
}

void thomas::Engine::Update(float aDeltaTime)
{
	m_SceneService->Update(aDeltaTime);
}

void thomas::Engine::Render()
{
	m_GraphicService->Clear();
	m_SceneService->Draw();
	m_GraphicService->Present();
}

