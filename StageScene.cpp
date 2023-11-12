#include "StageScene.h"
#include "ImGuiManager.h"

void StageScene::Init()
{
	player_ = std::make_unique<Player>();
	player_->Init();
	enemy_ = std::make_unique<Enemy>();
	enemy_->Init();
}

void StageScene::Update()
{
	// 更新
	player_->Update();
	enemy_->Update();
	if (enemy_->GetDead()) {
		sceneNo = CLEAR;
	}

	// 当たり判定
	CheckAllCollision();

	ImGui::Begin("enemy");
	ImGui::Text("pos.x : %.2f pos.y : %.2f", enemy_->GetPosition().x, enemy_->GetPosition().y);
	ImGui::Text("rad : %.2f", enemy_->GetRadius());
	ImGui::Text("isDead : %d", enemy_->GetDead());
	ImGui::End();
}

void StageScene::Draw()
{
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
