#ifndef SPRITE_H
#define SPRITE_H

#include <QPixmap>

#include "../common.h"

class Sprite
{
public:
	Sprite(QString const& filename);
	QPixmap const& get(Direction direction) const;
private:
	QPixmap const image;
	QPixmap const reversedImage;
};

#endif // SPRITE_H
