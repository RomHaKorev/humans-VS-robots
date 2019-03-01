QT += quick widgets svg
CONFIG += c++14

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    $$PWD/core/circularsprites.cpp \
    $$PWD/core/sprite.cpp \
    $$PWD/core/spritesmanager.cpp \
    $$PWD/elements/characteritem.cpp \
    $$PWD/elements/hero.cpp \
    $$PWD/model/character.cpp \
    $$PWD/elements/grounditem.cpp \
    $$PWD/model/ground.cpp \
    $$PWD/model/world.cpp \
    $$PWD/model/elementengine.cpp \
    $$PWD/elements/bullet.cpp

HEADERS += \
    $$PWD/core/circularsprites.h \
    $$PWD/core/sprite.h \
    $$PWD/core/spritesmanager.h \
    $$PWD/elements/characteritem.h \
    $$PWD/elements/hero.h \
    $$PWD/model/character.h \
    $$PWD/common.h \
    $$PWD/elements/grounditem.h \
    $$PWD/model/ground.h \
    $$PWD/model/world.h \
    $$PWD/model/elementengine.h \
    $$PWD/elements/bullet.h

RESOURCES += $$PWD/qml.qrc \
    $$PWD/res.qrc

DISTFILES += \
    $$PWD/Game.qml
