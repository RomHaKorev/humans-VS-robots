import QtQuick 2.9
import QtQuick.Window 2.2
//import app.components 1.0
import QtQuick.Controls 2.2

Item {
	id: rooItem
	visible: true
	anchors.fill: parent
	signal moveLeft()
	signal moveRight()
	signal stand()
	signal kneel()

	Item {
		focus: true
		anchors.fill: parent
		property int lastKey: null
		property double lastPressed: 0
		Keys.onPressed: {
			var now = new Date().getTime();
			if ((lastKey === event.key) && (now - lastPressed < 200))
			{
				event.accepted = false
				return
			}
			if (event.key === Qt.Key_Right)
			{
				hero.moveRight()
				lastKey = event.key
				lastPressed = now
				event.accepted = true;
			}
			else if (event.key === Qt.Key_Down) {
				hero.kneel()
				lastKey = event.key
				lastPressed = now
				event.accepted = true;
			}
		}

		Keys.onReleased: {
			if (event.isAutoRepeat)
				return;
			switch (event.key)
			{
			case Qt.Key_Right:
			case Qt.Key_Left:
			case Qt.Key_Down:
				hero.stand()
				event.accepted = true;
				break;
			default:
			}
		}

		/*Hero {
			id: hero
			//anchors.centerIn: parent
		}
		Hero {
			id: hero2
			anchors.left: hero.right
			anchors.top: hero.top
		}*/

		Row {
			anchors.bottom: parent.bottom
			Button {
				text: "->"
				onPressed: {
					moveRight()
				}
				onReleased: {
					stand()
				}
			}
			Button {
				id: btn;
				text: "v"
				onPressed: {
					kneel();
				}
				onReleased: {
					stand();
				}
			}

		}
	}
}
