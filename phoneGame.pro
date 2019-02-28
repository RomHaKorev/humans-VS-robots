QT += quick widgets svg xml
CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core/circularsprites.cpp \
    core/sprite.cpp \
    core/spritesmanager.cpp \
    elements/characteritem.cpp \
    elements/hero.cpp \
    model/character.cpp \
    main.cpp \
    elements/grounditem.cpp \
    model/ground.cpp \
    model/world.cpp \
    model/elementengine.cpp \
    elements/bullet.cpp \
    elements/robot.cpp

HEADERS += \
    core/circularsprites.h \
    core/sprite.h \
    core/spritesmanager.h \
    elements/characteritem.h \
    elements/hero.h \
    model/character.h \
    common.h \
    elements/grounditem.h \
    model/ground.h \
    model/world.h \
    model/elementengine.h \
    elements/bullet.h \
    elements/robot.h \
    elements/elements.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



INCLUDEPATH += C:/Users/Dim/WRK/lib/boost_1_67_0/boost_1_67_0

DISTFILES += \
    main.qml
