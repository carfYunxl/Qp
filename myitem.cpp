#include "myitem.h"
#include <QMouseEvent>
myItem::myItem(QWidget *parent):QWidget(parent)
{

}
void myItem::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        firstPoint = event->pos();
    }
}
void myItem::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        secondPoint = event->pos();
    }
}
