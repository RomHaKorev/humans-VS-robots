#include "hero.h"

#include "../model/character.h"
#include "../core/spritesmanager.h"

#include "../model/ground.h"

Hero::Hero(): CharacterItem(SpritesManager::hero(0))
{

}
