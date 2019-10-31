#ifndef THOMAS_WORLD_H
#define THOMAS_WORLD_H

#include <Entity.h>
#include <string>
#include <map>
#include <list>
#include <vector>

namespace thomas
{
	class World
	{
	public:
		void Add(const std::string& aName, Entity* aEntity);
		Entity* FindByName(const std::string& aName);

		void StartEntities();
		void Unload();
		void Clean();
		void Update(float aDeltaTime);
		void Draw();
		bool GetUpdateDown() { return m_UpdateDone; }
		bool GetDrawDone() { return m_DrawDone; }


	private:
		typedef std::map<std::string, Entity*> TEntityMap;
		typedef std::vector<Entity*> TEntityVector;

		bool m_UpdateDone;
		bool m_DrawDone;

		TEntityMap m_Entities;
		TEntityVector m_MembersToUpdate;
		TEntityVector m_MembersToDraw;
		TEntityVector  m_MembersToStart;
	};
}
#endif