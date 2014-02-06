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
import QtQuick.Controls 1.1

Rectangle {
    id: cours
    objectName: "coursItem"
    property int index: 0
    width: 550
    height: 30
    color: "#878ca6"
    radius: 5
    visible: false
    opacity: visible ? 1 : 0
    Behavior on opacity {
        NumberAnimation {duration:500}
    }

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#ffffff"
        }

        GradientStop {
            position: 1
            color: "#878ca6"
        }
    }

    property  alias text: coursName.text

    SpinBox {
        id: credits
        objectName: "credits"
        x: 390
        y: 4
        width: 41
        height: 22
        maximumValue: 60
    }

    SpinBox {
        id: points
        objectName: "points"
        x: 437
        y: 4
        width: 56
        height: 22
        decimals: 1
        value: 0
        stepSize: 1
        maximumValue: 20
    }

    TextField {
        id: coursName
        objectName: "coursName"
        x: 8
        y: 4
        width: 376
        height: 22
        text: ""
        placeholderText: "Cours"
    }

    ToolButton {
        id: toolButton1
        x: 520
        y: 4
        width: 22
        height: 22
        Behavior on opacity {
            NumberAnimation {duration: 500}
        }

        opacity: hovered ? 1 : 0.4
        iconSource: "list-remove22.png"
        onClicked: appMan.removeCours(index)

    }
}
