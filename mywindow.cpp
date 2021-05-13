#include "mywindow.h"
#include "ui_mywindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <QVBoxLayout>

#include <QToolBar>
#include <QMessageBox>
#include <QDebug>
#include <QDockWidget>
#include <QFileDialog>
#include <QDateTime>
#include <QTimer>
#include <QSplitter>
#include <QGraphicsView>
#include <QMimeData>
myWindow::myWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myWindow)
{
    ui->setupUi(this);
    /*----------------title bar---------------*/
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
    /*-------------------------------*/
    /*---------------title bar button----------------*/
    lb1 = new QToolButton(w1);
    lb1->setIcon(QIcon(":/icon/ac.jpg"));
    lb1->resize(50,50);
    connect(lb1,&QToolButton::clicked,this,&myWindow::changeImage);
    lb2 = new QLabel(w1);
    lb2->resize(50,50);
    lb2->setText("娱乐休闲");
    lb2->setFont(QFont("微软雅黑",15));

    QToolButton *b1 = new QToolButton(w1);b1->setIcon(QIcon(":/icon/key.jpg"));b1->setFont(QFont("Times",12));
    connect(b1,&QToolButton::clicked,this,&myWindow::showMinimized);

    QToolButton *b2 = new QToolButton(w1);b2->setIcon(QIcon(":/icon/gr.jpg"));b2->setFont(QFont("Times",12));
    connect(b2,&QToolButton::clicked,this,&myWindow::showMaximized);

    QToolButton *b3 = new QToolButton(w1);b3->setIcon(QIcon(":/icon/windowclose.jpg"));b3->setFont(QFont("Times",12));
    connect(b3,&QToolButton::clicked,this,&myWindow::close);

    QToolButton *b4 = new QToolButton(w1);b4->setIcon(QIcon(":/icon/palate.jpg"));b4->setFont(QFont("Times",12));
    connect(b4,&QToolButton::clicked,this,&myWindow::showNormal);

    QHBoxLayout *ly = new QHBoxLayout(w1);
    ly->addWidget(lb1);
    ly->addWidget(lb2);
    ly->addStretch();
    ly->addWidget(b1);
    ly->addWidget(b2);
    ly->addWidget(b4);
    ly->addWidget(b3);
    w1->setLayout(ly);
    /*---------------file----------------*/
    QAction *fOpen = new QAction(QIcon(":/icon/ac.jpg"),"Open",this);
    QAction *fSave = new QAction(QIcon(":/icon/addf.jpg"),"Save",this);
    QAction *fSaveAs = new QAction(QIcon(":/icon/addf2.jpg"),"Save as",this);
    QAction *fNew = new QAction(QIcon(":/icon/back.jpg"),"New",this);
    QList<QAction *> file = {
                            fOpen,
                            fSave,
                            fSaveAs,
                            fNew
                            };
    /*----------------draw---------------*/
    QAction *dPoint = new QAction(QIcon(":/icon/back2.jpg"),"Point",this);
    QAction *dLine = new QAction(QIcon(":/icon/bea.jpg"),"Line",this);
    QAction *dRect = new QAction(QIcon(":/icon/cam.jpg"),"Rect",this);
    QAction *dCircle = new QAction(QIcon(":/icon/count.jpg"),"Circle",this);
    QList<QAction *> draw = {
                            dPoint,dLine,dRect,dCircle
                            };

    connect(dLine,&QAction::triggered,[=](){

    });
    /*----------------Image---------------*/
    QAction *iLoad = new QAction(QIcon(":/icon/dark.jpg"),"Load",this);
    QAction *iChange = new QAction(QIcon(":/icon/edit.jpg"),"Change",this);
    QAction *iSaveImage = new QAction(QIcon(":/icon/edit2.jpg"),"SaveImage",this);
    QAction *iDeleteImage = new QAction(QIcon(":/icon/edit3.jpg"),"DeleteImage",this);
    QList<QAction *> Image = {
                            iLoad,iChange,iSaveImage,iDeleteImage
                            };
    /*----------------Video---------------*/
    QAction *vOpenVideo = new QAction(QIcon(":/icon/dark.jpg"),"OpenVideo",this);
    QAction *vStop = new QAction(QIcon(":/icon/edit.jpg"),"Stop",this);
    QAction *vContinue = new QAction(QIcon(":/icon/edit2.jpg"),"Continue",this);
    QAction *vSaveVideo = new QAction(QIcon(":/icon/edit3.jpg"),"SaveVideo",this);
    QList<QAction *> Video = {
                            vOpenVideo,vStop,vContinue,vSaveVideo
                            };
    /*----------------Contact---------------*/
    QAction *ctac1 = new QAction(QIcon(":/icon/exit.jpg"),"tac1",this);
    QAction *ctac2 = new QAction(QIcon(":/icon/fenzu.jpg"),"Stop",this);
    QAction *ctac3 = new QAction(QIcon(":/icon/g1.jpg"),"Continue",this);
    QAction *ctac4 = new QAction(QIcon(":/icon/g2.jpg"),"SaveVideo",this);
    QList<QAction *> Contact = {
                            ctac1,ctac2,ctac3,ctac4
                            };
    /*----------------toolbar---------------*/
    QToolBar *toolb1 = addToolBar("File");
    toolb1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    toolb1->setStyleSheet("background-color:lightgray;");
    toolb1->addActions(file);

    QToolBar *toolb2 = addToolBar("Draw");
    toolb2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    toolb2->setStyleSheet("background-color:lightgray;");
    toolb2->addActions(draw);

    QToolBar *toolb3 = addToolBar("Image");
    toolb3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    toolb3->setStyleSheet("background-color:lightgray;");
    toolb3->addActions(Image);

    QToolBar *toolb4 = addToolBar("Video");
    toolb4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    toolb4->setStyleSheet("background-color:lightgray;");
    toolb4->addActions(Video);
    /*----------------menu---------------*/
    QMenu *mfile = mbar->addMenu("File");
    mfile->addActions(file);

    QMenu *mEdit = mbar->addMenu("Edit");
    mEdit->addActions(draw);

    QMenu *mImage = mbar->addMenu("Image");
    mImage->addActions(Image);

    QMenu *mVideo = mbar->addMenu("Video");
    mVideo->addActions(Video);

    QMenu *mContact = mbar->addMenu("Contact");
    mContact->addActions(Contact);
    /*----------------dockWidget---------------*/
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

    l2->addWidget(btn3);
    l2->addWidget(btn4);
    l2->addWidget(btn5);
    l2->addStretch(0);
    page2->setLayout(l2);
    tbw->addTab(page2,"second page");
    dockwidget->setWidget(tbw);

    /*----------------statusBar---------------*/
    QLabel *lab_s = new QLabel(this);
    lab_s->setStyleSheet("color:white");
    statusBar()->addPermanentWidget(lab_s);

    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        lab_s->setText(QDateTime::currentDateTime().toString());
    });
    timer->start(10);

    /*----------------CentralWidget---------------*/
    QSplitter *splitter = new QSplitter(Qt::Horizontal,this);
    setCentralWidget(splitter);
    te = new QTextEdit(this);
    QGraphicsView *graphicsView = new QGraphicsView(this);
    splitter->addWidget(graphicsView);
    splitter->addWidget(te);
    splitter->setStretchFactor(0,3);
    splitter->setStretchFactor(1,1);

    /*----------------te可拖放显示文件---------------*/
    te->setAcceptDrops(false);
    this->setAcceptDrops(true);
    /*----------------graphicsView---------------*/

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
void myWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/uri-list"))
    {
        event->acceptProposedAction();
    }
}

void myWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())
    {
        return;
    }

    QString fileName = urls.first().toLocalFile();
    if(fileName.isEmpty())
    {
        return;
    }
    if(readFile(fileName))
    {
        te->setWindowTitle(tr("%1 - %2").arg(fileName).arg(tr("Drag File")));
    }


}
bool myWindow::readFile(QString filePath)
{
    QFile file(filePath);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QString read = file.readAll();
            te->setText(read);
            file.close();
            return true;
        }
        else
            return false;
}
