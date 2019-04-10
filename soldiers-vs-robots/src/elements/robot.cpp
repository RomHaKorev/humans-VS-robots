#include "robot.h"
#include "../core/spritesmanager.h"
#include "../model/world.h"

Robot::Robot(): CharacterItem(World::engine(), SpritesManager::robot(0))
{
	//turnLeft();
}
