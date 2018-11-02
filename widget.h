#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QUdpSocket>
#include <QHostAddress>
#include <QAudio>
#include <QAudioInput>
#include <QAudioFormat>
#include <QIODevice>
#include <QByteArray>
#include <QBuffer>
#include <QDebug>

#include <opencv2/opencv.hpp>
using namespace cv;

struct audio_t{
    char data[1024];
    int length;
};

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    QUdpSocket udp_audio_sender;
    QUdpSocket udp_video_sender;
    QHostAddress dst_addr;
    quint16 port;

    QAudioFormat audio_fmt;
    QAudioInput *audio_input;
    QIODevice *audio_input_dev;
    audio_t au;

    VideoCapture camera;
    QTimer timer;

private slots:
    void audio_read_slot();
    void timer_out_slot();
    void on_quitBtn_clicked();
    void on_openCamBtn_clicked();
    void on_closeCamBtn_clicked();

public:
    void init();


};

#endif // WIDGET_H
