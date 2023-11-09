#pragma once
#include <memory>

#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

class GameManager
{
private:
	// シーンごと
	std::unique_ptr<IScene> sceneArr_[3];

	// どのステージかの管理変数
	int currentSceneNo_; // 現在
	int prevSceneNo_; // 過去

public:
	GameManager();
	~GameManager() {};

	int Run();

};

