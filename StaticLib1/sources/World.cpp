#include "..\include\World.h"
#include <list>
#include <vector>
#include <Engine.h>
#include <Entity.h>

class Entity;

void thomas::World::Add(const std::string & aName, Entity * aEntity)
{
	if (m_Entities.count(aName) == 0)
	{
		m_MembersToStart.push_back(aEntity);
		m_Entities[aName] = aEntity;
	}
}

thomas::Entity* thomas::World::FindByName(const std::string & aName)
{
	if (m_Entities.count(aName) > 0)
	{
		return m_Entities.find(aName)->second;
	}
	else
	{
		return nullptr;
	}
}

void thomas::World::StartEntities()
{
	std::vector<Entity*>::iterator itr;
	for (itr = m_MembersToStart.begin(); itr != m_MembersToStart.end(); itr++)
	{
		(*itr)->Start();

		if ((*itr)->CanDraw())
		{
			m_MembersToDraw.push_back(*itr);
		}
		if ((*itr)->CanUpdate())
		{
			m_MembersToUpdate.push_back(*itr);
		}
	}
	m_MembersToStart.clear();
}

void thomas::World::Unload()
{
	TEntityMap::iterator itr;
	for (itr = m_Entities.begin(); itr != m_Entities.end(); ++itr)
	{
		delete itr->second;
	}

	for (std::vector<Entity*>::iterator itr = m_MembersToStart.begin(); itr != m_MembersToStart.end(); itr++)
	{
		delete(*itr);
	}

	m_Entities.clear();
	m_MembersToUpdate.clear();
	m_MembersToDraw.clear();
	m_MembersToStart.clear();
}

void thomas::World::Clean()
{
	Unload();
	thomas::Engine::Instance().GetLog().LogUsingVS("Cleaning done\n");
}

void thomas::World::Update(float aDeltaTime)
{
	m_UpdateDone = false;
	std::vector<Entity*>::iterator itr;
	for (itr = m_MembersToUpdate.begin(); itr != m_MembersToUpdate.end(); ++itr)
	{
		(*itr)->Update(aDeltaTime);
	}
	m_UpdateDone = true;
}

void thomas::World::Draw()
{
	m_DrawDone = false;
	std::vector<Entity*>::iterator itr;
	for (itr = m_MembersToDraw.begin(); itr != m_MembersToDraw.end(); ++itr)
	{
		(*itr)->Draw();
	}
	m_DrawDone = true;
}
