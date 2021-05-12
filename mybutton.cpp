#include "mybutton.h"
#include <QPainter>
myButton::myButton(QWidget *parent) : QToolButton(parent)
{
    this->setAutoRaise(true);
    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}
void myButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPen myPen(Qt::white);
    QBrush myBrush(Qt::blue);

    painter.setPen(myPen);
    painter.setBrush(myBrush);
    qreal x = qMin(width(),height());
    painter.drawEllipse(0,0,x,x);

    QPen pen(Qt::red,2);
    painter.setPen(pen);

    QLineF l(QPointF(x/2 - x*1.414/6,x/2 - x*1.414/6),QPointF(x/2 + x*1.414/6,x/2 + x*1.414/6));
    QLineF l2(QPointF(x/2 - x*1.414/6,x/2 + x*1.414/6),QPointF(x/2 + x*1.414/6,x/2 - x*1.414/6));
    painter.drawLine(l);
    painter.drawLine(l2);
}
