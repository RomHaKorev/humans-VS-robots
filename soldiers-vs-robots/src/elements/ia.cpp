#include "ia.h"

#include "characteritem.h"

#include "characterfactory.h"

IA::IA(CharacterType type, CharacterItem* character, CharacterFactory* parent) : QObject(parent),
	character(character),
	type(type),
	internalTimerId(startTimer(100)),
	factory(parent)
{
	connect(character, &CharacterItem::destroyed, this, &IA::deleteLater);
}


void IA::timerEvent(QTimerEvent* event)
{
	for (CharacterItem const* sibling: factory->sibling(character))
	{
		if (sibling == character)
			continue;
		if (character->inSight(sibling))
		{
			character->stand();
			character->fire();
			return;
		}

	}
	character->moveLeft();
}
