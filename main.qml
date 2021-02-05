import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: "recebe - Atividade 2"

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: "Receber"
                width: parent.width
                onClicked: {
                    stackView.push("Receber.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: "Sair/Encerrar"
                width: parent.width
                onClicked: {
                    Qt.quit()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "Principal.qml"
        anchors.fill: parent
    }
}
