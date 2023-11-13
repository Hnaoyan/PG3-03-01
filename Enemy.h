#pragma once
#include <Vector2.h>
#include <stdint.h>

#include "EnemyState.h"
#include "Collider.h"

class EnemyState;

class Enemy : public Collider
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
	/// <summary>
	/// コールバック
	/// </summary>
	void OnCollision() override;
	/// <summary>
	/// ステート変更
	/// </summary>
	/// <param name="state"></param>
	void ChangeState(EnemyState* state);
	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="moveVector"></param>
	void MoveUpdate(Vector2& moveVector);
private:
	EnemyState* state_ = nullptr;

	Vector2 position_ = {};
	float radius_ = {};
	bool isDead_ = false;
	uint32_t colorCode_ = 0xffffffff;
	int hp_ = 0;

public:
	Vector2 GetPosition() override { return position_; }
	bool GetDead() { return isDead_; }
	int GetHp() { return hp_; }
};

