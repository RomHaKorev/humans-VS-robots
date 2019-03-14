#include "charactertesthelper.h"

#include <elements/characteritem.h>

#include <QTest>

CharacterTestHelper::CharacterTestHelper(CharacterItem* sut):
	sut(sut)
{}


bool CharacterTestHelper::isMovingToRight()
{
	qreal currentDistance = sut->distance();
	QTest::qWait(100);
	qreal newDistance = sut->distance();
	return currentDistance < newDistance;
}

bool CharacterTestHelper::isMovingToLeft()
{
	qreal currentDistance = sut->distance();
	QTest::qWait(100);
	qreal newDistance = sut->distance();
	qDebug() << currentDistance << newDistance;
	return currentDistance > newDistance;
}
