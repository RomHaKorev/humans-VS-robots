#include "hero.h"

#include "../core/spritesmanager.h"
#include "../model/world.h"

Hero::Hero(): CharacterItem(World::engine(), SpritesManager::hero(0))
{

}
