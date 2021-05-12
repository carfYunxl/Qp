#ifndef MYBUTTONCLOSE_H
#define MYBUTTONCLOSE_H

#include <QWidget>

namespace Ui {
class myButtonClose;
}

class myButtonClose : public QWidget
{
    Q_OBJECT

public:
    explicit myButtonClose(QWidget *parent = nullptr);
    ~myButtonClose();

    void paintEvent(QPaintEvent *event) override;
public:signals:
    void clicked();
private:
    Ui::myButtonClose *ui;
};

#endif // MYBUTTONCLOSE_H
