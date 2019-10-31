#ifndef THOMAS_ISCENE_H
#define THOMAS_ISCENE_H

#include <IService.h>
#include <GameState.h>
#include <Entity.h>
#include <string>


namespace thomas
{
	class IScene : public IService
	{

	public:
		virtual ~IScene() = default;
		
		virtual bool Initialize() = 0;
		virtual void Clean() = 0;
		virtual void Register(const std::string& aId, GameState* aState) = 0;
		virtual void Load(const std::string& aId) = 0;

		virtual void Update(float aDeltaTime) = 0;
		virtual void Draw() = 0;

		virtual void AddEntity(const std::string& aId, Entity* aEntity) = 0;
		virtual Entity* FindEntity(const std::string& aId) = 0; // va devoir caster en player
	};
}
#endif
