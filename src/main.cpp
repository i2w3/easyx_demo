#include <iostream>

#include <fmt/core.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "utils.h"

int main()
{
    std::cout << "Hello World by std!" << std::endl;
    fmt::print("Hello World by fmt!\n");

    google::InitGoogleLogging("MyDino");
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_ERROR);


    LOG(INFO) << "Info message";
    LOG(WARNING) << "Warning Message";
    // LOG(ERROR) << "Error Message";
    // LOG(FATAL) << "Fatal Message"; // 会自动关闭程序
    cv::Mat img = cv::imread("./res/test.jpg");
    if (img.empty())
	{
		std::cout << "Not found Image!" << std::endl;
		return -1;
	}
    cv::namedWindow("img", cv::WINDOW_NORMAL);
    cv::resizeWindow("img", img.cols, img.rows);
    cv::imshow("img", img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    //打开本地0号摄像头播放
	OpenAndPlayLocalCamera(0); 
    system("pause");
    google::ShutdownGoogleLogging();
    return 0;
}
