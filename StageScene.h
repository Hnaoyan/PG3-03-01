#pragma once
#include "IScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Collider.h"
#include "InputHandler.h"
#include "ICommand.h"

#include <memory>

class StageScene : public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
	~StageScene() = default;

public:
	void CheckAllCollision();
	void CheckAllPair(Collider* colliderA,Collider* colliderB);

private:
	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_;

	std::unique_ptr<InputHandler> inputHandler_;
	ICommand* command_ = nullptr;

};

