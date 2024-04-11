#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
	// A constructor specific to Thomas;
	Thomas();

	// The Overriden input handler for Thomas;
	bool virtual handleInput();
};