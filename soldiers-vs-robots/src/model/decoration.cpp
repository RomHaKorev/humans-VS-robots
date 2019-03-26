#include "decoration.h"

#include <QPainter>
#include <QDebug>

Decoration::Decoration(int id, QString const& filename):
    sprite(filename),
    id(id)
{}


QPixmap Decoration::pixmap(bool random) const
{
	return sprite.get();
}
