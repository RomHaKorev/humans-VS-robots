#include "robot.h"
#include "../core/spritesmanager.h"

Robot::Robot(): CharacterItem(SpritesManager::robot(0))
{
	turnLeft();
}
