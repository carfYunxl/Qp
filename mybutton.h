#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QToolButton>

class myButton : public QToolButton
{
    Q_OBJECT
public:
    explicit myButton(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *) override;

signals:

};

#endif // MYBUTTON_H
