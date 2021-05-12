#include "mywindow.h"
#include "ui_mywindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <QVBoxLayout>

#include <QToolBar>
#include <QMessageBox>
#include <QDebug>
#include <QDockWidget>
#include "mybuttonclose.h"
#include <QFileDialog>
#include "mybutton.h"
myWindow::myWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myWindow)
{
    ui->setupUi(this);
    setContentsMargins(0,0,0,0);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QWidget *widget = new QWidget(this);
    widget->setStyleSheet("background-color:black;"
                          "border-radius:1px");

    QVBoxLayout *layout = new QVBoxLayout;
    widget->setLayout(layout);
    widget->setContentsMargins(0,0,0,0);

    QWidget *w1 = new QWidget(this);
    w1->setFixedHeight(50);

    w1->setStyleSheet("background-color:black;"
                       "border-radius:1px;"
                      "color:white");
    QMenuBar *mbar = new QMenuBar(this);
    layout->addWidget(w1);
    layout->addWidget(mbar);
    setMenuWidget(widget);
    mbar->setStyleSheet("background-color:black;"
                        "border-radius:1px;"
                       "color:white");

    /**/
    lb1 = new QToolButton(w1);
    lb1->setIcon(QIcon(":/icon/ac.jpg"));
    lb1->resize(50,50);
    connect(lb1,&QToolButton::clicked,this,&myWindow::changeImage);
    lb2 = new QLabel(w1);
    lb2->resize(50,50);
    lb2->setText("娱乐休闲");
    lb2->setFont(QFont("微软雅黑",15));

    QToolButton *b1 = new QToolButton(w1);b1->setText("min");b1->setFont(QFont("Times",12));
    connect(b1,&QToolButton::clicked,this,&myWindow::showMinimized);

    QToolButton *b2 = new QToolButton(w1);b2->setText("max");b2->setFont(QFont("Times",12));
    connect(b2,&QToolButton::clicked,this,&myWindow::showMaximized);

//    QToolButton *b3 = new QToolButton(w1);b3->setText("close");b3->setFont(QFont("Times",12));
//    connect(b3,&QToolButton::clicked,this,&myWindow::close);
    myButton *bb = new myButton(w1);
    connect(bb,&myButton::clicked,this,&myWindow::close);

    QHBoxLayout *ly = new QHBoxLayout(w1);
    ly->addWidget(lb1);
    ly->addWidget(lb2);
    ly->addStretch();
    ly->addWidget(b1);
    ly->addWidget(b2);
    ly->addWidget(bb);
    //ly->addWidget(b3);

    w1->setLayout(ly);
    /**/

    QList<QAction *> pf = {new QAction(QIcon(":/icon/Q1.jpg"),"1",this),
                           new QAction(QIcon(":/icon/Q2.jpg"),"2",this),
                           new QAction(QIcon(":/icon/Q3.jpg"),"3",this),
                           new QAction(QIcon(":/icon/Q4.jpg"),"4",this)};
    QToolBar *toolb1 = addToolBar("11111111");
    toolb1->setStyleSheet("background-color:lightgray;");
    toolb1->addActions(pf);

    QToolBar *toolb2 = addToolBar("222222222222");
    toolb2->setStyleSheet("background-color:lightgray;");
    toolb2->addActions(pf);

    QToolBar *toolb3 = addToolBar("333333333");
    toolb3->setStyleSheet("background-color:lightgray;");
    toolb3->addActions(pf);

    QToolBar *toolb4 = addToolBar("44444444444");
    toolb4->setStyleSheet("background-color:lightgray;");
    toolb4->addActions(pf);

    QMenu *file = mbar->addMenu("File");
    file->addActions(pf);

    QMenu *Edit = mbar->addMenu("Edit");
    Edit->addActions(pf);

    QMenu *Image = mbar->addMenu("Image");
    Image->addActions(pf);

    QMenu *Video = mbar->addMenu("Video");
    Video->addActions(pf);

    QMenu *Contact = mbar->addMenu("Contact");
    Contact->addActions(pf);

    QDockWidget *dockwidget = new QDockWidget("my dockWidget",this);
    dockwidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    dockwidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    this->addDockWidget(Qt::LeftDockWidgetArea,dockwidget);

    QTabWidget *tbw = new QTabWidget;

    QWidget *page1 = new QWidget;
    QVBoxLayout *l1 = new QVBoxLayout;


    QToolButton *btn11 = new QToolButton;
    btn11->setText("第一个按钮！");
    QToolButton *btn21 = new QToolButton;
    btn21->setText("第二个按钮！");
    QToolButton *btn31 = new QToolButton;
    btn31->setText("第三个按钮！");
    l1->addWidget(btn11);
    l1->addWidget(btn21);
    l1->addWidget(btn31);
    l1->addStretch(0);
    page1->setLayout(l1);
    tbw->addTab(page1,"first page");

    QWidget *page2 = new QWidget;
    QVBoxLayout *l2 = new QVBoxLayout;
    QToolButton *btn3 = new QToolButton;
    btn3->setText("第四个按钮！");
    QToolButton *btn4 = new QToolButton;
    btn4->setText("第五个按钮！");
    QToolButton *btn5 = new QToolButton;
    btn5->setText("第六个按钮！");
    btn5->setStyleSheet("selection-background-color:red");

    //
    myButton *b = new myButton();
    b->resize(60,60);
    b->setText("****");
    connect(b,&myButton::clicked,[=](){
        qDebug()<<"pressed!";
        myButtonClose *button = new myButtonClose(nullptr);
        button->show();
    });
    b->setStyleSheet("selection-background-color:red");
    //
    l2->addWidget(btn3);
    l2->addWidget(btn4);
    l2->addWidget(btn5);
    l2->addWidget(b);
    l2->addStretch(0);
    page2->setLayout(l2);
    tbw->addTab(page2,"second page");


    dockwidget->setWidget(tbw);


}

myWindow::~myWindow()
{
    delete ui;
}
void myWindow::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPen myPen(Qt::black,3,Qt::SolidLine,Qt::SquareCap);
    QBrush myBrush(Qt::black);
    painter.setPen(myPen);
    painter.setBrush(myBrush);
    //painter.drawRect(0,0,this->width(),this->height());
    painter.drawRoundRect(0,0,this->width(),this->height(),5,5);
}
void myWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->buttons() == Qt::RightButton)
    {
        int ret = QMessageBox::information(this,"tips:","right can close the window,Yes to do that!",
                                 QMessageBox::Yes |
                                 QMessageBox::No,QMessageBox::Yes);
        if(ret == QMessageBox::Yes)
        {
            this->close();
        }
    }else if(event->buttons() == Qt::MiddleButton)
    {
        cPoint = event->globalPos()-frameGeometry().topLeft();
    }
}
void myWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(event->buttons() == Qt::MiddleButton)
    {
        move(event->globalPos()-cPoint);
    }
}
void myWindow::changeImage()
{
    QString path =  QFileDialog::getOpenFileName(this,"open Image","open","*.*");
    if(!path.isEmpty())
    {
        lb1->setIcon(QIcon(path));
    }
}
