#pragma once
#include "Enemy.h"

class Enemy;

class EnemyState {
protected:
	Enemy* enemy_ = nullptr;
public:
	virtual void SetEnemy(Enemy* enemy) { enemy_ = enemy; }
	virtual void Update() {};
};

class EnemyStopState : public EnemyState {
public:
	void Update();
};

class EnemyMoveState : public EnemyState {
public:
	EnemyMoveState();
	void Update();
private:
	bool isMoveLeft_ = false;
};


