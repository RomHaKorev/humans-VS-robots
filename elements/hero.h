#ifndef HERO_H
#define HERO_H

#include "characteritem.h"

class Ground;
class Character;

class Hero : public CharacterItem
{
public:
	Hero(Ground const& ground);
};

#endif // HERO_H
