#pragma once
#include <Novice.h>

class InputKey
{
private:
	// キー入力結果を受け取る箱
	static char keys[256];
	static char preKeys[256];
	
public:
	static void Input() {
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
	}

	static bool IsPress(char keyNumber)
	{
		return keys[keyNumber];
	}

	static bool IsTrigger(char keyNumber)
	{
		return !preKeys[keyNumber] && keys[keyNumber];
	}

};

char InputKey::keys[256] = { 0 };

char InputKey::preKeys[256] = { 0 };