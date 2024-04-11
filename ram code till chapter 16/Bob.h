#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	// A constructor specific to bob;
	Bob();

	// The overriden input handler for bob;
	bool virtual handleInput();
};
