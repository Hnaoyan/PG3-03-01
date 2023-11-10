#include "InputKey.h"

char InputKey::keys[256] = { 0 };
char InputKey::preKeys[256] = { 0 };

void InputKey::Input() {
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}


bool InputKey::IsPress(char keyNumber)
{
	return keys[keyNumber];
}

bool InputKey::IsTrigger(char keyNumber)
{
	return !preKeys[keyNumber] && keys[keyNumber];
}
