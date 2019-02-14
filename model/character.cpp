#include "character.h"

#include <QPainter>
#include <QDebug>

Character::Character(QDir const& spritesDirectory):
	standing(spritesDirectory.filePath("standing.png")),
	kneeling(spritesDirectory.filePath("kneeling.png")),
	runningSteps(CircularSprites(QDir(spritesDirectory.filePath("running"))))
{}

void Character::paint(QPainter& painter, Move moveStatus, Direction direction, unsigned int step) const
{
	painter.drawPixmap(0, 0, pixmap(moveStatus, direction, step));
}

QPixmap const& Character::pixmap(Move moveStatus, Direction direction, unsigned int step) const
{
	switch(moveStatus)
	{
	case Move::Standing:
		return standing.get(direction);
	case Move::Kneeling:
		return kneeling.get(direction);
	case Move::Moving:
		return runningSteps.at(step, direction);
	}
	return standing.get(direction);
}

unsigned int Character::runStepCount() const
{
	return runningSteps.size();
}
