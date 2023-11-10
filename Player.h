#pragma once
#include "Vector2.h"
#include "PlayerBullet.h"

#include <stdint.h>
#include <list>

class Player
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	/// <summary>
	/// 設定
	/// </summary>
	void Setting();
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// 移動入力
	/// </summary>
	void Movement();

	/// <summary>
	/// 射撃処理
	/// </summary>
	void Fire();

	/// <summary>
	/// 弾の処理
	/// </summary>
	void BulletUpdate();

	/// <summary>
	/// 弾の生成
	/// </summary>
	void GenerateBullet();

private:
	// 座標
	Vector2 position_ = {};
	// 移動速度
	Vector2 velocity_ = {};
	// サイズ
	float radius_ = {};

public:
	Vector2 GetPostion() { return position_; }
	float GetRadius() { return radius_; }

private:
	struct WorkFire {
		uint32_t kFireRate_ = 60;
		uint32_t coolTimer_ = 0;
	};

	WorkFire workFire_;

	std::list<PlayerBullet*> bullets_;

};

