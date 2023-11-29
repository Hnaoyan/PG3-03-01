#include "Player.h"
#include "InputKey.h"

#include <Novice.h>

void Player::Init()
{
	position_ = { 1280.0f / 2.0f,720.0f / 2.0f };
	radius_ = 20.0f;
	SetRadius(radius_);
	Setting();
}

void Player::Setting()
{
	workFire_.kFireRate_ = 10;

}

void Player::Update()
{
	// 移動入力
	velocity_ = {};
	//Movement();
	// 射撃処理
	Fire();
	// 弾の処理
	BulletUpdate();

	position_.x += velocity_.x;
	position_.y += velocity_.y;
}

void Player::Draw()
{
	for (PlayerBullet* bullet : bullets_) {
		bullet->Draw();
	}

	// 円の描画
	Novice::DrawEllipse(int(position_.x), int(position_.y), int(radius_), int(radius_), 0.0f, 0x00FF00DD, kFillModeSolid);

}

void Player::OnCollision()
{
}

void Player::MoveRight()
{
	float speed = 4.0f;
	velocity_.x += speed;
	position_.x += velocity_.x;
}

void Player::MoveLeft()
{
	float speed = 4.0f;
	velocity_.x -= speed;
	position_.x += velocity_.x;
}

void Player::MoveUp()
{
	float speed = 4.0f;
	velocity_.y -= speed;
	position_.y += velocity_.y;
}

void Player::MoveDown()
{
	float speed = 4.0f;
	velocity_.y += speed;
	position_.y += velocity_.y;
}

void Player::Movement()
{
	//float speed = 4.0f;
	//velocity_ = {};

	//if (InputKey::IsPress(DIK_W)) {
	//	velocity_.y -= speed;
	//}
	//else if (InputKey::IsPress(DIK_S)) {
	//	velocity_.y += speed;
	//}

	//if (InputKey::IsPress(DIK_A)) {
	//	velocity_.x -= speed;
	//}
	//else if (InputKey::IsPress(DIK_D)) {
	//	velocity_.x += speed;
	//}

}

void Player::Fire()
{
	if (InputKey::IsPress(DIK_SPACE)) {
		workFire_.coolTimer_++;
		if (workFire_.coolTimer_ >= workFire_.kFireRate_) {
			GenerateBullet();
			workFire_.coolTimer_ = 0;
		}
	}
}

void Player::BulletUpdate()
{
	// 削除処理
	bullets_.remove_if([](PlayerBullet* bullet) {
		if (bullet->GetIsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});

	// 更新処理
	for (PlayerBullet* bullet : bullets_) {
		bullet->Update();
	}
}

void Player::GenerateBullet()
{
	// 初期値変数
	const float kBulletSpeed = 5.0f;
	Vector2 bulletVelocity = { 0, -kBulletSpeed };

	// 生成・初期化
	PlayerBullet* newBullet = new PlayerBullet();
	newBullet->Init(position_,bulletVelocity);

	// リストに追加
	bullets_.push_back(newBullet);

}
