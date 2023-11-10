#pragma once
#include <Vector2.h>

class PlayerBullet
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

private:
	Vector2 position_;
	Vector2 velocity_;
	float radius_;
	bool isDead_;

	const float kBulletRadius = 10.0f;

public: // アクセッサ
	// 座標
	Vector2 GetPostion() { return position_; }
	void SetPosition(Vector2& position) { position_ = position; }
	// サイズ
	float GetRadius() { return radius_; }
	void SetRadius(float radius) { radius_ = radius; }	
	// 死亡フラグ
	bool GetIsDead() { return isDead_; }
	void SetIsDead(bool isDead) { isDead_ = isDead; }

};

