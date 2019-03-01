import QtQuick 2.0
import QtTest 1.0

import "."

TestCase {
    name: "GameWorld"
    //property  foobar: Qt.createComponent("qrc:/Game.qml");
     Loader { id: sut;
     width: 500}

    /*Game {
        id: sut
    }*/

    //var component = Qt.createComponent("qrc:/Game.qml");

    function initTestCase() {
        sut.source = "qrc:/Game.qml"
        sut.rooItem.width = 500
        sut.rooItem.height = 500
    }

    function cleanupTestCase() {
    }

    function test_case1() {
        compare(1 + 1, 2, "sanity check");
        verify(true);
    }
}
