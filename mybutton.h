#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QToolButton>
class myButton : public QToolButton
{
    Q_OBJECT
public:
    myButton(QWidget *parent = nullptr){}
    ~myButton(){}
    void enterEvent(QEvent *) override;
    void leaveEvent(QEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
private:

};

#endif // MYBUTTON_H
