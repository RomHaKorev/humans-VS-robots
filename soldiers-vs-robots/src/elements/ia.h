#ifndef IA_H
#define IA_H

#include <QObject>

#include "common.h"

class CharacterItem;
class CharacterFactory;

class IA : public QObject
{
	Q_OBJECT
	friend CharacterFactory;
private:
	explicit IA(CharacterType type, CharacterItem* character, CharacterFactory *parent);
	virtual void timerEvent(QTimerEvent* event) override;
	CharacterItem* const character;
	CharacterType const type;
	int const internalTimerId;
private:
	CharacterFactory const* factory;
};

#endif // IA_H
