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
    if (InputKey::IsPress(DIK_W)) {
        return presskeyW_;
    }
    if (InputKey::IsPress(DIK_S)) {
        return pressKeyS_;
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

void InputHandler::AssignMoveUpCommand2PressKeyW()
{
    ICommand* command = new MoveUpCommand();
    this->presskeyW_ = command;

}

void InputHandler::AssignMoveDownCommand2PressKeyS()
{
    ICommand* command = new MoveUpCommand();
    this->pressKeyS_ = command;
}
