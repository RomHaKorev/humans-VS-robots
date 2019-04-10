#include "characterfactory.h"

#include "robot.h"
#include "hero.h"
#include "ia.h"

CharacterFactory::CharacterFactory(QObject *parent) : QObject(parent)
{

}


CharacterItem* CharacterFactory::createCharacter(CharacterType type, int layerIndex)
{
	if (type == CharacterType::Ennemy)
	{
		Robot* robot = new Robot();
		new IA(type, robot, this);
		registerCharacter(robot, layerIndex);
		return robot;
	}
	return nullptr;
}

void CharacterFactory::registerCharacter(CharacterItem const * character, int layerIndex)
{
	qDebug() << Q_FUNC_INFO << layerIndex << character;
	if (!layers.contains(layerIndex))
		layers.insert(layerIndex, Layer());
	layers[layerIndex].append(character);
}

CharacterFactory::Layer const CharacterFactory::sibling(const CharacterItem * item) const
{
	qDebug() << Q_FUNC_INFO << layers;
	return layers.value(item->layerIndex(), Layer());
}
