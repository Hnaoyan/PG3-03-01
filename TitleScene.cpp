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

	Novice::DrawEllipse(int(1280 / 2), int(720 / 2), 30, 30, 0.0f, WHITE, kFillModeSolid);

}
