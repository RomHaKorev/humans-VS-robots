#ifndef CHARACTER_H
#define CHARACTER_H

#include <QQuickPaintedItem>
#include <QDir>
#include <QPixmap>
#include <list>

#include "../core/circularsprites.h"
#include "../core/sprite.h"

#include "../common.h"

class Character
{
public:
	QPixmap const& pixmap(Move move, Direction direction, unsigned int step=0) const;
	void paint(QPainter& painter, Move move, Direction direction, unsigned int step=0) const;
	Character(QDir const& spritesDirectory);
	unsigned int runStepCount() const;
private:
	Sprite const standing;
	Sprite const kneeling;
	CircularSprites const runningSteps;
};

#endif // CHARACTER_H
