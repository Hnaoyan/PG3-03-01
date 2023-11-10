#pragma once
#include <Vector2.h>

class Enemy
{
public:
	void Init();
	void Update();
	void Draw();

private:
	Vector2 position_ = {};
	float radius_ = {};

public:
	Vector2 GetPostion() { return position_; }
	float GetRadius() { return radius_; }

};

