#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHostAddress src_ip = QHostAddress::Any;
    quint16 src_port = 10086;

    sender.bind(src_ip, src_port);

    dst_ip = QHostAddress("10.200.44.68");
    dst_port = 10086;


    connect(&timer, SIGNAL(timeout()), this, SLOT(timer_out_slot()));

}

Widget::~Widget()
{
    camera.release();
    delete ui;
}

void Widget::on_openCamBtn_clicked()
{
    camera.open(0);
    timer.start(33);
    ui->openCamBtn->setEnabled(false);
}

void Widget::timer_out_slot()
{
    Mat frame;

    camera.read(frame);

    cvtColor(frame, frame, CV_BGR2RGB);

    QImage image((unsigned char*)(frame.data),
                 frame.cols,
                 frame.rows,
                 QImage::Format_RGB888);

    ui->pictureLabel->setPixmap(QPixmap::fromImage(image));
    ui->pictureLabel->resize(image.width(), image.height());


    QByteArray array;
    QBuffer buffer(&array);

    image.save(&buffer, "JPEG");

    QByteArray ss = qCompress(array, 5);  // 数据压缩，压缩比为5
    //QByteArray vv = ss.toBase64();  // 数据加密算法

    sender.writeDatagram(ss, dst_ip, dst_port);
}






