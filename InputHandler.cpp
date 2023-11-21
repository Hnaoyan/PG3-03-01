#include "InputHandler.h"
#include "InputKey.h"

ICommand* InputHandler::HandleInput()
{
    if (InputKey::IsPress(DIK_A)) {
        return pressKeyA_;
    }
    if (InputKey::IsPress(DIK_D)) {
        return pressKeyD_;
    }
    return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
    ICommand* command = new MoveLeftCommand();
    this->pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
    ICommand* command = new MoveRightCommand();
    this->pressKeyD_ = command;
}
