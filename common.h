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

QSize const characterSize(50, 50);

#endif // COMMON_H
