#ifndef THOMAS_ENGINE_H //si lengine nest pas definie definie le
#define THOMAS_ENGINE_H

#include <string>
#include <Windows.h> // visual studio
#include <IAudio.h>
#include <IGraphic.h>
#include <IInput.h>
#include <ITimer.h>
#include <IScene.h>
#include <ILog.h>
#include <ICollider.h>


#define SAFE_CLEAN(x) if((x) != nullptr) (x)->Clean(); delete (x); (x) = nullptr;

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG

namespace thomas
{
	class Engine
	{
	public:
		bool Initialize(const std::string& aTitle, int aWidth, int aHeight);
		void Start();
		void Stop();
		void Clean();
		void ProcessInput();
		void Update(float aDealtaTime);
		void Render();

		static Engine& Instance()
		{
			static Engine instance;
			return instance;
		}

		IAudio& GetAudio()const { return* m_AudioService; }
		IGraphic& GetGraphic()const { return* m_GraphicService; }
		IInput& GetInput()const { return* m_InputService; }
		ITimer& GetTimer()const { return* m_TimerService; }
		IScene& GetScene()const { return* m_SceneService; }
		ILog& GetLog()const { return* m_LogService; }
		ICollider& GetCollider()const { return* m_ColliderService; }





	private:
		int CircleX = 400;
		int CircleY = 400;
		Engine() {}
		bool m_IsRunning{ false };
		bool m_IsInit{ false };

		IAudio* m_AudioService{ nullptr };
		IGraphic* m_GraphicService{ nullptr };
		IInput* m_InputService{ nullptr };
		ITimer* m_TimerService{ nullptr };
		IScene* m_SceneService{ nullptr };
		ILog* m_LogService{ nullptr };
		ICollider* m_ColliderService{ nullptr };

	};
}
#endif