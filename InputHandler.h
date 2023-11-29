#pragma once
#include <ICommand.h>

class InputHandler
{
public:
	ICommand* HandleInput();

	void AssignMoveLeftCommand2PressKeyA();

	void AssignMoveRightCommand2PressKeyD();

	void AssignMoveUpCommand2PressKeyW();

	void AssignMoveDownCommand2PressKeyS();

private:
	ICommand* pressKeyA_;
	ICommand* pressKeyD_;
	ICommand* presskeyW_;
	ICommand* pressKeyS_;

};

