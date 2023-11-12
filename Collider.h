#pragma once
#include "Vector2.h"

class Collider
{
private:
	// サイズ
	float radius_;

public:
	float GetRadius() { return radius_; }
	void SetRadius(float radius) { radius_ = radius; }

	virtual void OnCollision() {};
	virtual Vector2 GetPosition() = 0;

};

