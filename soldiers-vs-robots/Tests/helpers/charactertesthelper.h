#ifndef CHARACTERTESTHELPER_H
#define CHARACTERTESTHELPER_H

class CharacterItem;

class CharacterTestHelper
{
public:
	CharacterTestHelper(CharacterItem* sut);
	bool isMovingToRight();
	bool isMovingToLeft();
private:
	CharacterItem* sut;
};

#endif // CHARACTERTESTHELPER_H
