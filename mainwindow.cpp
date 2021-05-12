#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QLabel>
#include <QToolButton>
#include <QTabBar>
mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent)
{

//    QMenuBar *menub = new QMenuBar(this);
//    menub->setFont(QFont("Times", 10, QFont::Bold));
//    menub->setStyleSheet("background-color:green");
//    QMenu *filemenu1 = menub->addMenu("File1");
//    QMenu *filemenu2 = menub->addMenu("File2");

    QWidget *widget = new QWidget(this);
    widget->setStyleSheet("background-color:blue");
    //setMenuWidget(widget);

    QList<QAction*>pf = {new QAction("1",this),new QAction("2",this),new QAction("3",this)};
//    filemenu1->addActions(pf);
//    filemenu2->addActions(pf);

    QToolBar *toolb1 = addToolBar("qqq");
    toolb1->setMovable(true);
    toolb1->addActions(pf);

    QLabel *lable = new QLabel(this);
    setCentralWidget(lable);
    lable->setStyleSheet("background-color:yellow");

    QDockWidget *dockWidget1 = new QDockWidget("myDockWidget",this);
    dockWidget1->setAllowedAreas(Qt::LeftDockWidgetArea |
                                Qt::RightDockWidgetArea |
                                Qt::TopDockWidgetArea |
                                Qt::BottomDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea,dockWidget1);

    dockWidget1->setStyleSheet("background-color:red");
    QToolButton *btn1 = new QToolButton(this);
    QToolButton *btn2 = new QToolButton(this);

    dockWidget1->setWidget(btn1);
    dockWidget1->setWidget(btn2);

    statusBar();
}
