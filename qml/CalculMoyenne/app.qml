//   CalculMoyenne allows to compute the mean point from different courses
//   result ponderate by their associated credits.
//   Copyright (C) 2014  Manuel Tondeur
//
//   This file is part of CalculMoyenne.
//
//   CalculMoyenne is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   CalculMoyenne is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with CalculMoyenne.  If not, see <http://www.gnu.org/licenses/>.

import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.1

ApplicationWindow {
    id: mainWind
    visible: true
    title: qsTr("Hello World")
    width: 600
    minimumWidth: 570
    height: 480
    minimumHeight: 300

    menuBar: MenuBar {
        objectName: "menuBar"
        Menu {
            title: qsTr("File")

            MenuItem {
                text: qsTr("Open list")
                onTriggered: appMan.openList()
            }

            MenuItem {
                text: qsTr("Save list")
                onTriggered: appMan.saveList()
            }

            MenuItem {
                text: qsTr("Add cours")
                onTriggered: appMan.addCours()
            }
            MenuItem {
                text: qsTr("Compute mean")
                onTriggered: appMan.computeMean()
            }

            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
    }

    toolBar: ToolBar {
        id: toolBar
        objectName: "toolbar"
        width: parent.width
        height: 46
        anchors.horizontalCenter: parent.horizontalCenter
        Row {
            anchors.left: parent.left
            anchors.leftMargin: 10
            spacing: 10
            ToolButton {
                iconSource: "document-open-folder.png"
                onClicked: appMan.openList()
            }

            ToolButton {
                iconSource: "document-save.png"
                onClicked: appMan.saveList()
            }

            ToolButton {
                tooltip: "Add cours"
                iconSource: "list-add.png"
                onClicked: appMan.addCours()
            }
            ToolButton {
                tooltip: "Remove cours"
                iconSource: "list-remove.png"
                onClicked: appMan.removeCours(-1)
            }
        }
    }

    Button {
        id: computeButton
        objectName: "boutton"
        text: qsTr("Compute")
        anchors.horizontalCenterOffset: -100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 4

        onClicked: {
            appMan.computeMean()
        }
    }

    TextField {
        placeholderText: "Mean"
        objectName: "result"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 5
    }

    ScrollView {
        objectName: "scrollArea"
        x: 13
        width: 574
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 35
        anchors.horizontalCenter: parent.horizontalCenter
        Column {
            id: column1
            anchors.horizontalCenterOffset: 0
            objectName: "coursColumn"
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 5

            Cours {visible: true}
        }
    }
}
