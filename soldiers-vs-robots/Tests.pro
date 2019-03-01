include(./config.pri)

CONFIG += warn_on qmltestcase

TEMPLATE = app

DISTFILES += \
    tst_gameworld.qml \
    Tests/tst_gameworld.qml

SOURCES = main_tests.cpp

include(./src/src.pri)

RESOURCES += \
    Tests/qml_tests.qrc
