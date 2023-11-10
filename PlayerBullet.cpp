#include "PlayerBullet.h"

#include <Novice.h>

void PlayerBullet::Init(Vector2& position, Vector2& velocity)
{
	// 座標
	position_ = position;
	// 移動ベクトル
	velocity_ = velocity;
	// サイズ
	radius_ = kBulletRadius;
}

void PlayerBullet::Update()
{
	// 画面外で消える判定
	const float kDeadZone = 20.0f;
	if (position_.y <= 0 - kDeadZone) {
		isDead_ = true;
	}
	else if (position_.y >= 1280.0f + kDeadZone) {
		isDead_ = true;
	}

	// 移動速度処理
	const float kAddSpeed = 0.2f;
	if (velocity_.y > 0) {
		velocity_.y += kAddSpeed;
	}
	else {
		velocity_.y -= kAddSpeed;
	}

	position_.x += velocity_.x;
	position_.y += velocity_.y;

}

void PlayerBullet::Draw()
{

	Novice::DrawEllipse(int(position_.x), int(position_.y), int(radius_), int(radius_), 0.0f, BLACK, kFillModeSolid);

}
