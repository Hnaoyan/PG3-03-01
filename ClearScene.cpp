#include "ClearScene.h"
#include<Novice.h>

void ClearScene::Init()
{
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Clear");
	Novice::DrawBox(int((1280 / 2) - 100), int((720 / 2) - 100), 200, 200, 0.0f, GREEN, kFillModeSolid);
}
