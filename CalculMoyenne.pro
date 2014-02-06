#   CalculMoyenne allows to compute the mean point from different courses
#   result ponderate by their associated credits.
#   Copyright (C) 2014  Manuel Tondeur
#
#   This file is part of CalculMoyenne.
#
#   CalculMoyenne is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   CalculMoyenne is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with CalculMoyenne.  If not, see <http://www.gnu.org/licenses/>.

# Add more folders to ship with the application, here
folder_01.source = qml/CalculMoyenne
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    appmanager.cpp

# Installation path
# target.path =

OTHER_FILES += \
    qml/CalculMoyenne/app.qml \
    qml/CalculMoyenne/list-add.png \
    qml/CalculMoyenne/Cours.qml \
    qml/CalculMoyenne/list-remove22.png \
    qml/CalculMoyenne/document-open-folder.png \
    qml/CalculMoyenne/document-save.png \
    qml/CalculMoyenne/list-remove.png \
    gpl.txt \
    README.txt


HEADERS += \
    appmanager.h

QT += qml quick widgets
