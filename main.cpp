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

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "appmanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine(QStringLiteral("qml/CalculMoyenne/app.qml"));

    AppManager appMan(engine);
    engine.rootContext()->setContextProperty("appMan", &appMan);

    return app.exec();
}
