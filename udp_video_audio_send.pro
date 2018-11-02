#-------------------------------------------------
#
# Project created by QtCreator 2018-11-02T11:57:10
#
#-------------------------------------------------

QT       += core gui
QT       += network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = udp_video_audio_send
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h

FORMS += \
        widget.ui

LIBS += -L/usr/local/lib -I/usr/local/include/opencv -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_objdetect -lopencv_video -lopencv_videoio -lopencv_videostab

#INCLUDEPATH += E:/opencv/opencv_qt/include\
#               E:/opencv/opencv_qt/include/opencv\
#               E:/opencv/opencv_qt/include/opencv2

#LIBS += -L E:/opencv/opencv_qt/lib/libopencv_*.a

