QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mybutton.cpp \
    mybuttonclose.cpp \
    mywindow.cpp

HEADERS += \
    mainwindow.h \
    mybutton.h \
    mybuttonclose.h \
    mywindow.h

FORMS += \
    mybuttonclose.ui \
    mywindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icon/Q1.jpg \
    icon/Q2.jpg \
    icon/Q3.jpg \
    icon/Q4.jpg \
    icon/QQ_style.jpg \
    icon/ac.jpg \
    icon/addf.jpg \
    icon/addf2.jpg \
    icon/back.jpg \
    icon/back2.jpg \
    icon/bea.jpg \
    icon/cam.jpg \
    icon/count.jpg \
    icon/dark.jpg \
    icon/edit.jpg \
    icon/edit2.jpg \
    icon/edit3.jpg \
    icon/exit.jpg \
    icon/fenzu .jpg \
    icon/fileopen.jpg \
    icon/forword.jpg \
    icon/g1.gif \
    icon/g2.gif \
    icon/g3.gif \
    icon/gr.jpg \
    icon/head.jpg \
    icon/key.jpg \
    icon/lauch.jpg \
    icon/lock.jpg \
    icon/lock.png \
    icon/man.jpg \
    icon/man.png \
    icon/more.jpg \
    icon/ocean.jpg \
    icon/palate.jpg \
    icon/people.jpg \
    icon/play.jpg \
    icon/play2.jpg \
    icon/set.jpg \
    icon/set2.jpg \
    icon/set3.jpg \
    icon/set3.png \
    icon/stop.jpg \
    icon/uht.jpg \
    icon/windowclose.jpg \
    icon/windowclose2.jpg \
    icon/windowclose3.jpg

RESOURCES += \
    req.qrc
