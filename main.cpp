#include <Novice.h>
#include <memory>

#include "GameManager.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	std::unique_ptr<GameManager> gameManager_ = std::make_unique<GameManager>();

	gameManager_->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
