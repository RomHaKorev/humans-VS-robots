include(src/src.pri)
include(config.pri)

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

TEMPLATE = app

SOURCES +=  Tests/tst_characterunittests.cpp \
    Tests/helpers/charactertesthelper.cpp

HEADERS += \
    Tests/helpers/charactertesthelper.h
