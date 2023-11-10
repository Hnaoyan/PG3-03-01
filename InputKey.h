#pragma once
#include <Novice.h>

class InputKey
{
private:
	// キー入力結果を受け取る箱
	static char keys[256];
	static char preKeys[256];
	
public:
	static void Input();

	static bool IsPress(char keyNumber);

	static bool IsTrigger(char keyNumber);

};
