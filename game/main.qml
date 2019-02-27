/*import QtQuick 2.9
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
}*/

import QtQuick 2.9
import QtQuick.Window 2.2
import app.components 1.0
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.12

Item {
	id: app
	visible: true
	anchors.fill: parent

	// You get free licenseKeys from https://v-play.net/licenseKey
	// With a licenseKey you can:
	//  * Publish your games & apps for the app stores
	//  * Remove the V-Play Splash Screen or set a custom one (available with the Pro Licenses)
	//  * Add plugins to monetize, analyze & improve your apps (available with the Pro Licenses)
	//licenseKey: "<generate one from https://v-play.net/licenseKey>"

		TextField {
			id: appTextField
			x: 0
			y: 329
			width: 256
			height: 19
			anchors.centerIn: parent
			placeholderText: qsTr('Enter a Number')
		}

		TextField {
			id: appTextField1
			x: 0
			y: 329
			width: 256
			height: 19
			anchors.verticalCenterOffset: 50
			anchors.centerIn: parent
			placeholderText: qsTr('Enter a Number')
		}
		TextEdit {
			id: text1
			x: 0
			y: 620
			width: 24
			height: 20
			text: qsTr('A')
			font.pixelSize: 30
			anchors.horizontalCenter: appTextField1.horizontalCenter
		}

		Button {
			id: button
			x: 0
			y: 575
			width: 24
			height: 20
			text: qsTr("Click me please!")
			anchors.horizontalCenter: appTextField1.horizontalCenter
			enabled: true
			onClicked: {
				const v1 = parseInt(appTextField.text)
				const v2 = parseInt(appTextField1.text)
				   text1.text=qsTr('Sum: ' + ( v1 + v2))
			}

		}
	}
