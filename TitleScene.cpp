#include "TitleScene.h"
#include "InputKey.h"

#include <Novice.h>

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	if (InputKey::IsTrigger(DIK_SPACE)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Title");
	Novice::DrawBox(int((1280/2)-100),int((720/2)-100),200,200,0.0f,WHITE,kFillModeSolid);
}
