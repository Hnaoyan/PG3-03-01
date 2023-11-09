#include "GameManager.h"
#include "InputKey.h"

#include <Novice.h>

GameManager::GameManager()
{
	// 各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	//sceneArr_[STAGE] = std::make_unique<StageScene>();
	//sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	// 初期シーンの設定
	currentSceneNo_ = TITLE;

}

int GameManager::Run()
{
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		InputKey::Input();

		///
		/// ↓更新処理ここから
		///

		// シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		// 更新
		sceneArr_[currentSceneNo_]->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		sceneArr_[currentSceneNo_]->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputKey::IsTrigger(DIK_ESCAPE)) {
			break;
		}
	}
	return 0;
}
