#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QByteArray>
#include <QBuffer>

#include <opencv2/opencv.hpp>
using namespace cv;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_openCamBtn_clicked();
    void timer_out_slot();

private:
    Ui::Widget *ui;

    VideoCapture camera;
    QUdpSocket sender;
    QTimer timer;
    QHostAddress dst_ip;
    quint16 dst_port;


};

#endif // WIDGET_H
