import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.12


import app.components 1.0

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
			else if (event.key === Qt.Key_Left)
			{
				hero.moveLeft()
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
			else if (event.key === Qt.Key_Space)
			{
				hero.fire()
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
				gradient: Gradient {
					GradientStop { position: 0.0; color: "#6DCDF7" }
					GradientStop { position: 1.0; color: "#CDEEFC" }
				}
			}

			Item {
				anchors.fill: parent
				anchors.leftMargin: 0
				anchors.rightMargin: 0
				Ground {
					id: ground
					property int characterOffset: 200
					anchors.leftMargin: 0
					anchors.bottom: parent.bottom
					property int offset: 0
					x: {
						if ((width -hero.x) >= (parent.width - characterOffset) && hero.x > characterOffset)
						{
							offset = -hero.x + characterOffset
							return -hero.x + characterOffset
						}
						return offset
					}
					Item {
						id: heroLayer
						objectName: "heroLayer"
						anchors.fill: parent
						Hero {
							id: hero
							objectName: "hero"
							distance: ground.characterOffset
						}
					/*Robot {
						id: robot
						distance: 800
					}*/
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
