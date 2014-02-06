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

#include "appmanager.h"
#include <QFileDialog>
#include <iostream>

AppManager::AppManager(QQmlApplicationEngine &engine): coursNumber(1)
{
    _engine = &engine;
    _rootObject = engine.rootObjects().front();
    _columnCours = _rootObject->findChild<QQuickItem*>("coursColumn");
    _result =  _rootObject->findChild<QQuickItem*>("result");
    _scrollArea = _rootObject->findChild<QQuickItem*>("scrollArea");
}


void AppManager::addCours(QString title, float credit, float point)
{
    QQmlComponent component(_engine, QUrl::fromLocalFile("qml/CalculMoyenne/Cours.qml"));
    QObject *ob = component.create();
    QQuickItem *item = (QQuickItem*) ob;
    item->setParentItem(_columnCours);
    item->setParent(_columnCours);
    coursNumber++;
    item->setProperty("index", coursNumber);
    item->findChild<QQuickItem*>("coursName")->setProperty("text", title);
    item->findChild<QQuickItem*>("credits")->setProperty("value", credit);
    item->findChild<QQuickItem*>("points")->setProperty("value", point);
    //_scrollArea->setProperty("height", _columnCours->findChildren<QQuickItem *>("coursItem").size() * 35);
    item->setVisible(true);
}

void AppManager::removeCours(int index)
{
    std::cout << index << std::endl;
    itemList coursList = _columnCours->findChildren<QQuickItem *>("coursItem");
    if (coursList.size() < 2)
        return;

    //_scrollArea->setProperty("height", (_columnCours->findChildren<QQuickItem *>("coursItem").size() - 1) * 35);
    if (index < 0) {
        coursList.back()->setVisible(false);
        coursList.back()->deleteLater();
        return;
    }

    for (itemList::iterator it = coursList.begin(); it != coursList.end(); ++it)
    {
        if (index == (*it)->property("index") )
        {
            (*it)->setVisible(false);

            (*it)->deleteLater();
            return;
        }
    }
}

void AppManager::computeMean()
{
    float ponderatePoints = 0;
    uint totalCredits = 0;
    itemList coursList = _columnCours->findChildren<QQuickItem*>("coursItem");
    for (itemList::iterator it = coursList.begin(); it != coursList.end(); ++it)
    {
        QQuickItem* pointsItem = (*it)->findChild<QQuickItem*>("points");
        float point = pointsItem->property("value").toFloat();
        QQuickItem* creditsItem = (*it)->findChild<QQuickItem*>("credits");
        float credit = creditsItem->property("value").toFloat();

        totalCredits += credit;
        ponderatePoints += point * credit;
    }
    if (totalCredits == 0)
        return;

    _result->setProperty("text", QString::number(ponderatePoints/totalCredits));
}

void AppManager::saveList()
{
    QUrl path = QFileDialog::getSaveFileUrl();
    QFile fichierSauv(path.path());
    if (!fichierSauv.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&fichierSauv);
    itemList coursList = _columnCours->findChildren<QQuickItem*>("coursItem");
    for (itemList::iterator it = coursList.begin(); it != coursList.end(); ++it)
    {
        QString title = (*it)->findChild<QQuickItem *>("coursName")->property("text").toString();
        if (title.isEmpty())
            title = "__";

        float credits = (*it)->findChild<QQuickItem *>("credits")->property("value").toFloat();
        float points  = (*it)->findChild<QQuickItem *>("points")->property("value").toFloat();

        out << title.replace(QString(" "),QString("%")) << " " << credits << " " << points ;

        if (it != coursList.end() - 1)
            out << "\n";
    }
}

void AppManager::openList()
{
    QUrl path = QFileDialog::getOpenFileUrl();
    QFile fichierOpen(path.path());

    if (fichierOpen.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        itemList coursList = _columnCours->findChildren<QQuickItem*>("coursItem");
        for (itemList::iterator it = coursList.begin(); it != coursList.end(); ++it)
            (*it)->deleteLater();

        QTextStream in (&fichierOpen);
        QString title;
        float credit;
        float point;
        while (! in.atEnd())
        {
            in >> title;
            in >> credit;
            in >> point;

            if (title == "__")
                title = "";

            addCours(title.replace(QString("%"),QString(" ")),credit,point);
        }
    }
    computeMean();
}

