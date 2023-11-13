#include "Enemy.h"
#include "ImGuiManager.h"
#include <Novice.h>

void Enemy::Init()
{
	const float radiusValue = 30.0f;
	radius_ = radiusValue;
	SetRadius(radius_);
	position_ = { 1280.0f / 2.0f,80.0f };
	isDead_ = false;
	const int MaxHP = 10;
	hp_ = MaxHP;
	state_ = new EnemyStopState();
	state_->SetEnemy(this);
}

void Enemy::Update()
{
	colorCode_ = WHITE;
	state_->Update();

}

void Enemy::Draw()
{
	Novice::DrawEllipse(int(position_.x), int(position_.y), int(radius_), int(radius_), 0.0f, colorCode_, kFillModeSolid);
}

void Enemy::OnCollision()
{
	if (hp_ <= 0) {
		isDead_ = true;
	}
	else {
		hp_--;
	}
	colorCode_ = RED;
}

void Enemy::ChangeState(EnemyState* state)
{
	state_ = state;
	state_->SetEnemy(this);
}

void Enemy::MoveUpdate(Vector2& moveVector)
{
	position_.x += moveVector.x;
	position_.y += moveVector.y;
}

void EnemyStopState::Update()
{
	const int MaxHP = 10;
	if (enemy_->GetHp() <= MaxHP / 2) {
		enemy_->ChangeState(new EnemyMoveState());
	}
}

EnemyMoveState::EnemyMoveState()
{
	isMoveLeft_ = false;
}

void EnemyMoveState::Update()
{
	Vector2 moveVector = {};
	if (isMoveLeft_) {
		moveVector = { -2.0f,0 };
	}
	else {
		moveVector = { 2.0f,0 };
	}
	if (enemy_->GetPosition().x >= 1280.0f) {
		isMoveLeft_ = true;
	}
	if (enemy_->GetPosition().x <= 0) {
		isMoveLeft_ = false;
	}

	enemy_->MoveUpdate(moveVector);

}
