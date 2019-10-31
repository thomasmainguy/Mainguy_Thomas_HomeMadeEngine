#include "..\include\NullScene.h"

bool thomas::NullScene::Initialize()
{
	return true;
}

void thomas::NullScene::Clean()
{
}

void thomas::NullScene::Register(const std::string & aId, GameState * aState)
{
}

void thomas::NullScene::Load(const std::string & aId)
{
}

void thomas::NullScene::Update(float aDeltaTime)
{
}

void thomas::NullScene::Draw()
{
}

void thomas::NullScene::AddEntity(const std::string & aId, Entity * aEntity)
{
}

thomas::Entity * thomas::NullScene::FindEntity(const std::string & aId)
{
	return nullptr;
}
