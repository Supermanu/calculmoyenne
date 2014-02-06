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

#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickView>

class AppManager : public QObject
{
    typedef QList<QQuickItem *> itemList;
    Q_OBJECT
public:
    AppManager(QQmlApplicationEngine &engine);

public slots:
    void addCours(QString title = "", float credit = 0, float point = 0);
    void removeCours(int index = -1);
    void computeMean();

    void openList();
    void saveList();

private:
    uint coursNumber;
    QQmlApplicationEngine *_engine;
    QObject *_rootObject;
    QQuickItem *_columnCours;
    QQuickItem *_result;
    QQuickItem *_scrollArea;
};

#endif // APPMANAGER_H
