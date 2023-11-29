#include "IScene.h"

int IScene::sceneNo = 1;

IScene::~IScene()
{
}

int IScene::GetSceneNo()
{
	return sceneNo;
}
