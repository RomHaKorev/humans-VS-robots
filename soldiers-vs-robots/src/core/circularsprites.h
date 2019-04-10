#ifndef CIRCULARSPRITES_H
#define CIRCULARSPRITES_H

#include <QPixmap>
#include <QDir>

#include "../common.h"
#include "sprite.h"

class CircularSprites
{
public:
	CircularSprites(QDir const& directory, QSize const& size);
	QPixmap const& at(unsigned int step, Direction direction) const;
	unsigned int size() const;
private:
	static std::vector<Sprite> loadSprites(QDir const& directory, QSize const& size);
	std::vector<Sprite> const buffer;
};

#endif // CIRCULARSPRITES_H
