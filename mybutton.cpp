#include "mybutton.h"
#include <QPainter>
void myButton::enterEvent(QEvent *)
{
    QPainter painter(this);
    QPen myPen(Qt::black);
    QBrush myBrush(Qt::cyan);
    painter.setPen(myPen);
    painter.setBrush(myBrush);
    painter.drawRoundRect(0,0,width(),height(),5,5);
}
void myButton::leaveEvent(QEvent *)
{
    QPainter painter(this);
    QPen myPen(Qt::black);
    QBrush myBrush(Qt::green);

    painter.setPen(myPen);
    painter.setBrush(myBrush);

    painter.drawRoundRect(0,0,width(),height(),5,5);
}
void myButton::mousePressEvent(QMouseEvent *)
{
    QPainter painter(this);
    QPen myPen(Qt::black);
    QBrush myBrush(Qt::red);

    painter.setPen(myPen);
    painter.setBrush(myBrush);

    painter.drawRoundRect(0,0,width(),height(),5,5);
}
void myButton::mouseReleaseEvent(QMouseEvent *)
{
    QPainter painter(this);
    QPen myPen(Qt::black);
    QBrush myBrush(Qt::green);

    painter.setPen(myPen);
    painter.setBrush(myBrush);

    painter.drawRoundRect(0,0,width(),height(),5,5);
}
