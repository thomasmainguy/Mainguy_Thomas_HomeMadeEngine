#ifndef THOMAS_SCENEMANAGER_H
#define THOMAS_SCENEMANAGER_H

#include <World.h>
#include <GameState.h>
#include <map>
#include <IScene.h>

namespace thomas
{
	class SceneManager final : public IScene
	{
	public:
		virtual ~SceneManager() = default;

		virtual bool Initialize() override;
		virtual void Clean() override;

		void Register(const std::string& aId, GameState* aState) override;
		void Load(const std::string& aId) override;
		void Update(float aDeltaTime) override;
		void Draw() override;

		void AddEntity(const std::string& aId, Entity* aEntity) override;
		Entity* FindEntity(const std::string& aId) override; // va devoir caster en player


	private:
		typedef std::map<std::string, GameState*> TSceneMap;
		void LoadNextScene();

		World m_World;
		GameState* m_NextState{ nullptr };
		TSceneMap m_SceneMap;
	
	};
}
#endif