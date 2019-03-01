#ifndef CHARACTERTESTHELPER_H
#define CHARACTERTESTHELPER_H

class CharacterItem;

class CharacterTestHelper
{
public:
    CharacterTestHelper(CharacterItem* sut);
    bool isMovingToRight();
private:
    CharacterItem* sut;
};

#endif // CHARACTERTESTHELPER_H
