#pragma once
#include "Vector2.h"

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

	Vector2 position_ = {};
	Vector2 radius_ = {};

};

