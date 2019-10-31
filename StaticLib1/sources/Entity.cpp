#include <Entity.h>
#include <Engine.h>
#include <IScene.h>



thomas::IGraphic & thomas::Entity::GetGraphic() const
{
	return thomas::Engine::Instance().GetGraphic();
}

thomas::IInput & thomas::Entity::GetInput() const
{
	return thomas::Engine::Instance().GetInput();
}

thomas::IAudio & thomas::Entity::GetAudio() const
{
	return thomas::Engine::Instance().GetAudio();

}

thomas::ILog & thomas::Entity::GetLog() const
{
	return thomas::Engine::Instance().GetLog();
}

thomas::ICollider & thomas::Entity::GetCollider() const
{
	return thomas::Engine::Instance().GetCollider();
}

thomas::IScene & thomas::Entity::GetScene() const
{
	return thomas::Engine::Instance().GetScene();
}

