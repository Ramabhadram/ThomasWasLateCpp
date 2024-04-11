#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal = false;
	// Make a rect for all hos parts;
	FloatRect detectionZone = character.getPosition();

	// Make a FloatRect to test each block;
	FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Build a zone around Thomas to detect collisions;
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;

	// Thomas is quite tall, so check a few tiles vertically;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	// Make sure we don't test positions lower than zero or Higher than the end of the array;
	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;

	if (endX >= m_LM.getLevelSize().x) endX = m_LM.getLevelSize().x;
	if (endY >= m_LM.getLevelSize().y) endX = m_LM.getLevelSize().y;
	

	// Has the Character fallen out of the map?
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);
	if (!character.getPosition().intersects(level))
	{
		// Re spwan the character;
		character.spawn(m_LM.getStartPosition(), GRAVITY);
	}

	// Loop through all the loacl blocks;
	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			// Initialize the starting position of the current block;
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			// Has the Character been Burnt or drowned use head as this allows him to sink a bit;
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3)
			{
				if (character.getHead().intersects(block))
				{
					character.spawn(m_LM.getStartPosition(), GRAVITY);
				    // Which Sound should be played?
					if (m_ArrayLevel[y][x] == 2) // Fire, Ouch!
					{
							// Play the fire sound;
							m_SM.playFallInFire();
					}
					if (m_ArrayLevel[y][x] == 3)// Water
					{
						// Play a sound;
						m_SM.playFallInWater();
					}
				}
			}
			// Is Character colliding with a regular block;
			if (m_ArrayLevel[y][x] == 1)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if(character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}

				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}
			}
			// More collision detection here once we have;
			// Learned about particle effects;

			// Has the character reached the goal?
			if (m_ArrayLevel[y][x] == 4)
			{
				// Character has reached the goal;
				reachedGoal = true;
			}
		}
	}
	// All done, return, whether or not a new level might be required;
	return reachedGoal;
}