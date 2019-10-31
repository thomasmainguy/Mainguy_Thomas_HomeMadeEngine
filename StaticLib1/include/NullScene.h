#ifndef THOMAS_NULLSCENE_H
#define THOMAS_NULLSCENE_H

#include <IScene.h>
#include <GameState.h>
#include <string>
#include <Entity.h>

namespace thomas
{
	class NullScene final: public IScene
	{
	public:
		virtual ~NullScene() = default;

		virtual bool Initialize() override;
		virtual void Clean() override;
		virtual void Register(const std::string& aId, GameState* aState) override;
		virtual void Load(const std::string& aId) override;

		virtual void Update(float aDeltaTime) override;
		virtual void Draw() override;

		virtual void AddEntity(const std::string& aId, Entity* aEntity) override;
		virtual Entity* FindEntity(const std::string& aId) override; // va devoir caster en player
	};
}
#endif
