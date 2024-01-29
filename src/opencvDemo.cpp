#include <iostream>
#include <opencv2/opencv.hpp>

//打开本地摄像头，并播放视频
bool OpenAndPlayLocalCamera(const int& index)
{   
    
    using namespace cv;
    using namespace std;
	cout << "将要播放本地摄像头视频，按下空格键结束播放" << endl;
 
	VideoCapture capture;
	bool result = capture.open(index); //打开0号、或1号、或2号...摄像头
 
	//检查是否成功打开
	if (!capture.isOpened())
	{
		cout << "打开本地摄像头失败, 编号:" << index << endl;
		return result;
	}
 
	//打印视频参数：宽、高、每秒传输帧数
	cout << "width = " << capture.get(CAP_PROP_FRAME_WIDTH) << endl;
	cout << "height =" << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
	cout << "fps = " << capture.get(CAP_PROP_FPS) << endl;
 
	try
	{
		Mat frame;
		while (true)
		{
			capture >> frame;				//读取视频帧
			imshow("本地摄像头", frame);    //在名称为“本地摄像头”的窗口中显示视频
			if (32 == waitKey(1))			//按下空格键退出视频每帧的显示
			{
				cout << "按下空格键，退出播放" << endl;
				break;
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << "exception:" << e.what() << endl;
	}
 
	capture.release();
	destroyWindow("本地摄像头");
	cout << "视频文件播放完成" << endl << endl;
	return result;
}