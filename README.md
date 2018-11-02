# nanopc-t3-video-acquisition
1、在友善之臂的nanopc-t3开发板上，使用usb摄像头，进行视频采集、压缩与网络传输

2、注意：

（1）发送端也可以使用PC机，我的pc机上，opencv库放在E盘，此时的.pro文件配置为：
INCLUDEPATH += E:/opencv/opencv_qt/include\
               E:/opencv/opencv_qt/include/opencv\
               E:/opencv/opencv_qt/include/opencv2

LIBS += -L E:/opencv/opencv_qt/lib/libopencv_*.a


（2）发送端使用nanopc-t3时，此时的.pro文件配置为
LIBS += -L/usr/local/lib -I/usr/local/include/opencv -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_objdetect -lopencv_video -lopencv_videoio -lopencv_videostab

3、nanopc-t3安装opencv库的操作步骤，见官方wiki
