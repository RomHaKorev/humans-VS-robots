#ifndef TREE_H
#define TREE_H

#include <QDir>
#include <QPixmap>
#include "../core/sprite.h"

#include "../common.h"

class Decoration
{
public:
	QPixmap pixmap(bool random) const;
	Decoration(QString const& filename);
private:
	Sprite const sprite;
};

#endif // TREE_H
