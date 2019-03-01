#include <QtTest>
#include <QTest>
#include <QCoreApplication>


#include <model/world.h>
#include <src/elements/hero.h>

#include "helpers/charactertesthelper.h"

class CharacterUnitTests : public QObject
{
    Q_OBJECT

private:
    CharacterItem* sut;
public:
    CharacterUnitTests() {}
    ~CharacterUnitTests() {}

private slots:

void initTestCase()
{
    sut = new Hero();
    World::init(QSizeF(1000, 300));
}

void cleanupTestCase()
{
    sut->setDistance(0);
}

void test_whenAskToMoveRightThenHeroShouldMove()
{
    CharacterTestHelper helper(sut);
    sut->moveRight();
    QVERIFY(helper.isMovingToRight());
}

};

QTEST_MAIN(CharacterUnitTests)

#include "tst_characterunittests.moc"
