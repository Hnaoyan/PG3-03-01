#include "StageScene.h"
#include "Novice.h"
#include "ImGuiManager.h"

void StageScene::Init()
{
	player_ = std::make_unique<Player>();
	player_->Init();
	enemy_ = std::make_unique<Enemy>();
	enemy_->Init();

	inputHandler_ = std::make_unique<InputHandler>();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();

}

void StageScene::Update()
{
	command_ = inputHandler_.get()->HandleInput();

	if (this->command_) {
		command_->Exec(*player_);
	}

	// 更新
	player_->Update();
	enemy_->Update();
	if (enemy_->GetDead()) {
		sceneNo = CLEAR;
	}

	// 当たり判定
	CheckAllCollision();

}

void StageScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Game");

	// 描画
	player_->Draw();
	enemy_->Draw();
}

void StageScene::CheckAllCollision()
{
	// 衝突判定
	const std::list<PlayerBullet*>& bulletList = player_->GetBulletList();
	for (PlayerBullet* bullet : bulletList) {
		CheckAllPair(bullet, enemy_.get());
	}
}

void StageScene::CheckAllPair(Collider* colliderA, Collider* colliderB)
{
	// 座標
	Vector2 colliderPointA = colliderA->GetPosition();
	Vector2 colliderPointB = colliderB->GetPosition();
	// 距離・長さ
	float distance={sqrtf( powf(colliderPointA.x - colliderPointB.x, 2) + powf(colliderPointA.y - colliderPointB.y, 2) )};
	float radius = colliderA->GetRadius() + colliderB->GetRadius();
	// 判定
	if (distance <= radius){
   		colliderA->OnCollision();
		colliderB->OnCollision();
	}
}
