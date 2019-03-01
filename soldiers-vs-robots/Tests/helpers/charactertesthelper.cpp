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
