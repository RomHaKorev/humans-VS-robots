import QtQuick 2.9
import QtQuick.Window 2.2
import app.components 1.0
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.12

Item {
	id: rooItem
	visible: true
	anchors.fill: parent

	Item {
		focus: true
		anchors.fill: parent
		property int lastKey: 0
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

		Item {
			anchors.bottom: controls.top
			anchors.leftMargin: 0
			anchors.rightMargin: 0
			anchors.bottomMargin: 0
			anchors.left: parent.left
			anchors.right: parent.right
			anchors.top: parent.top
			Rectangle {
				id: background
				anchors.fill: parent;
				color: "#343434"
				Image { source: "/images/world/sky.png"; fillMode: Image.Stretch ; anchors.fill: parent }
			}

			Item {
				anchors.fill: parent
				anchors.leftMargin: parent.width/3
				anchors.rightMargin: 50
				Ground {
					id: ground
					anchors.leftMargin: 0
					anchors.bottom: parent.bottom
					property int offset: 0
					x: {
						if ((width -hero.x)>=parent.width)
						{
							offset = -hero.x
							return -hero.x
						}
						return offset
					}
					Hero {
						id: hero
					}
					Hero {
					}
				}
			}
		}

		Row {
			id: controls
			anchors.bottom: parent.bottom
			Button {
				text: "<-"
				onPressed: {
					hero.moveLeft()
				}
				onReleased: {
					hero.stand()
				}
			}
			Button {
				text: "v"
				onPressed: {
					hero.kneel();
				}
				onReleased: {
					hero.stand();
				}
			}
			Button {
				text: "->"
				onPressed: {
					hero.moveRight()
				}
				onReleased: {
					hero.stand()
				}
			}
			Button {
				text: "Fire"
				onClicked: {
					hero.fire()
				}
			}

		}
	}
}
