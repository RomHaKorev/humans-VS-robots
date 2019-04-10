#ifndef COMMON_H
#define COMMON_H

#include <QSize>

enum Move
{
	Standing = 0,
	Moving = 1,
	Kneeling = 2
};

enum Direction
{
	Left = 0,
	Right = 1
};

enum CharacterType
{
	Ally,
	Ennemy
};

QSize const characterSize(100, 100);
QSize const treeSize(220, 300);

#endif // COMMON_H
