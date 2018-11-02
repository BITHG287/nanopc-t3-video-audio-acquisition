#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    port = 6666;
    udp_audio_sender.bind(QHostAddress::Any, port);
    udp_video_sender.bind(QHostAddress::Any, port + 1);
    dst_addr.setAddress("10.200.44.67");

    audio_fmt.setSampleRate(8000);
    audio_fmt.setChannelCount(1);
    audio_fmt.setSampleSize(16);
    audio_fmt.setCodec("audio/pcm");
    audio_fmt.setSampleType(QAudioFormat::SignedInt);
    audio_fmt.setByteOrder(QAudioFormat::LittleEndian);
    audio_input = new QAudioInput(audio_fmt, this);
    audio_input_dev = audio_input->start();

    connect(audio_input_dev, SIGNAL(readyRead()), this, SLOT(audio_read_slot()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(timer_out_slot()));
}

void Widget::audio_read_slot()
{
    memset(&au, 0, sizeof(au));
    au.length = audio_input_dev->read(au.data, 1024);
    udp_audio_sender.writeDatagram((const char *)&au, sizeof(au), dst_addr, port);
}

void Widget::timer_out_slot()
{
    Mat frame;

    camera.read(frame);
    cvtColor(frame, frame, CV_BGR2RGB);

    QImage image((unsigned char *)(frame.data),
                 frame.cols,
                 frame.rows,
                 QImage::Format_RGB888);

    ui->imgLabel->setPixmap(QPixmap::fromImage(image));
    ui->imgLabel->resize(image.width(), image.height());

    QByteArray array;
    QBuffer buffer(&array);

    image.save(&buffer, "JPEG");
    QByteArray temp = qCompress(array, 5);

    udp_video_sender.writeDatagram(temp, dst_addr, port + 1);

}

void Widget::on_openCamBtn_clicked()
{
    ui->openCamBtn->setEnabled(false);
    //ui->quitBtn->setEnabled(false);
    camera.open(0);
    timer.start(30);
}

void Widget::on_quitBtn_clicked()
{
    timer.stop();
    camera.release();
    this->close();
}

void Widget::on_closeCamBtn_clicked()
{
    ui->quitBtn->setEnabled(true);
}
