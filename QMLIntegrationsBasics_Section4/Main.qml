import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls.Basic
import QMLIntegrationsBasics_Section4

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Integrations Basics")

    footer: Button {
        text: qsTr("Call Q_INVOKABLE method to reset ellipse's properties")
        onClicked: function() {
            slider.value = 25
            ellipse.setProperties(slider.value, "blue")
        }
    }

    header: Column {
        width: parent.width

        Button {
            width: parent.width
            text: qsTr("Select ellipse's color")
            onClicked: function() { colorDialog.open() }
        }

        Label {
            width: parent.width
            text: qsTr("Resize ellipse's border")
        }

        Slider {
            id: slider

            width: parent.width
            value: 25
            from: 0
            to: Math.min(ellipse.width, ellipse.height) / 2
        }
    }

    Ellipse {
        id: ellipse

        anchors.centerIn: parent
        width: 200
        height: 200
        color: "blue"
        border: slider.value

        onColorChanged: function() { ellipseInfo() }
    }

    ColorDialog {
        id: colorDialog

        selectedColor: ellipse.color
        onAccepted: ellipse.color = selectedColor
    }
}
