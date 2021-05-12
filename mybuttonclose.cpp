#include "mybuttonclose.h"
#include "ui_mybuttonclose.h"
#include <QPaintEvent>
#include <QPainter>
myButtonClose::myButtonClose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myButtonClose)
{
    emit clicked();
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

myButtonClose::~myButtonClose()
{
    delete ui;
}
void myButtonClose::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPen myPen(Qt::white);
    QBrush myBrush(Qt::white);

    painter.setPen(myPen);
    painter.setBrush(myBrush);
    qreal x = qMin(width(),height());
    painter.drawEllipse(0,0,x,x);

    QPen pen(Qt::blue,40);
    painter.setPen(pen);

    QLineF l(QPointF(x/2 - x*1.414/6,x/2 - x*1.414/6),QPointF(x/2 + x*1.414/6,x/2 + x*1.414/6));
    QLineF l2(QPointF(x/2 - x*1.414/6,x/2 + x*1.414/6),QPointF(x/2 + x*1.414/6,x/2 - x*1.414/6));
    painter.drawLine(l);
    painter.drawLine(l2);

}
