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
	sut->setDistance(0);
	World::init(QSizeF(1000, 300));
}

void cleanupTestCase()
{
	//sut->setDistance(0);
	sut->deleteLater();
}

void test_whenAskToMoveRightThenHeroShouldMove()
{
	CharacterTestHelper helper(sut);
	sut->moveRight();
	QVERIFY(helper.isMovingToRight());
}

void test_whenAskToMoveLeftThenHeroShouldMove()
{
	sut->setDistance(100);
	CharacterTestHelper helper(sut);
	sut->moveLeft();
	QVERIFY(helper.isMovingToLeft());
}

};

QTEST_MAIN(CharacterUnitTests)

#include "tst_characterunittests.moc"
