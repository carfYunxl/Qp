#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class myWindow; }
QT_END_NAMESPACE

class myWindow : public QMainWindow
{
    Q_OBJECT

public:
    myWindow(QWidget *parent = nullptr);
    ~myWindow();

    void paintEvent(QPaintEvent* event)override;
    void mousePressEvent(QMouseEvent* event)override;
    void mouseMoveEvent(QMouseEvent* event)override;
private:
    Ui::myWindow *ui;
    QPoint cPoint;
    QToolButton *lb1;
    QLabel *lb2;

public slots:
    void changeImage();
};
#endif // MYWINDOW_H
