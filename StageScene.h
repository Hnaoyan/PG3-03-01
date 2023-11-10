#pragma once
#include "IScene.h"
#include "Player.h"

#include <memory>

class StageScene : public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
	~StageScene() = default;

private:
	std::unique_ptr<Player> player_;

};

