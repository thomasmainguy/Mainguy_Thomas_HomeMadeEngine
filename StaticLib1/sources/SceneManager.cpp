#include "SceneManager.h"

bool thomas::SceneManager::Initialize()
{
	return true;
}

void thomas::SceneManager::Clean()
{
	for (TSceneMap::iterator tItr = m_SceneMap.begin(); tItr != m_SceneMap.end(); ++tItr)
	{
		delete tItr->second;
	}

	m_SceneMap.clear();
	m_World.Clean();
}

void thomas::SceneManager::Register(const std::string & aId, GameState * aState)
{
	if (m_SceneMap.count(aId) == 0) 
	{
		m_SceneMap[aId] = aState;
	}
}

void thomas::SceneManager::Load(const std::string & aId)
{
	if (m_SceneMap.count(aId) > 0)
	{
		m_NextState = m_SceneMap[aId];
	}
}

void thomas::SceneManager::Update(float aDeltaTime)
{
	m_World.Update(aDeltaTime);
	m_World.StartEntities(); 
	
	LoadNextScene();
}

void thomas::SceneManager::Draw()
{
	m_World.Draw();
}

void thomas::SceneManager::AddEntity(const std::string & aId, Entity * aEntity)
{
	if (m_World.FindByName(aId) != aEntity)
	{
		m_World.Add(aId, aEntity);
	}
}

thomas::Entity * thomas::SceneManager::FindEntity(const std::string & aId)
{
	return m_World.FindByName(aId);
}

void thomas::SceneManager::LoadNextScene()
{
	if (m_NextState != nullptr)
	{
		if (m_World.GetDrawDone() && m_World.GetUpdateDown())
		{
			m_World.Unload();
			m_NextState->Load();

			m_NextState = nullptr;
		}
	}
}