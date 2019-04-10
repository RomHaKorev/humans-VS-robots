#ifndef HERO_H
#define HERO_H

#include "characteritem.h"

class Hero : public CharacterItem
{
public:
	Hero();

//	virtual CharacterType type() const override { return CharacterType::Ally; }
};

#endif // HERO_H
