#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include <QObject>
#include <QMap>
#include <QSet>

#include "../common.h"

class CharacterItem;


class CharacterFactory : public QObject
{
	Q_OBJECT
	using Layer = QList<CharacterItem const *>;

public:
	explicit CharacterFactory(QObject *parent = nullptr);
	CharacterItem* createCharacter(CharacterType type, int layerIndex);
	void registerCharacter(CharacterItem const * character, int layerIndex);
	Layer const sibling(CharacterItem const *) const;
private:
	QMap<int, Layer> layers;
};

#endif // CHARACTERFACTORY_H
