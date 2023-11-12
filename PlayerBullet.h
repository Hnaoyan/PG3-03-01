#pragma once
#include <Vector2.h>
#include "Collider.h"

class PlayerBullet : public Collider
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Init(Vector2& position, Vector2& velocity);
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	/// <summary>
	/// コールバック
	/// </summary>
	void OnCollision() override;

private:
	Vector2 position_;
	Vector2 velocity_;
	float radius_;
	bool isDead_;

	const float kBulletRadius = 10.0f;

public: // アクセッサ
	// 座標
	Vector2 GetPosition() override { return position_; }

	// 死亡フラグ
	bool GetIsDead() { return isDead_; }
	void SetIsDead(bool isDead) { isDead_ = isDead; }

};

