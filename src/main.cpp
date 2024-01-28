#include <iostream>

#include <fmt/core.h>
#include <glog/logging.h>


int main()
{
    std::cout << "Hello World" << std::endl;
    fmt::print("Hello World!\n");

    google::InitGoogleLogging("MyDino");
    LOG(INFO) << "Info message";
    LOG(WARNING) << "Warning Message";
    LOG(ERROR) << "Error Message";
    // LOG(FATAL) << "Fatal Message"; // 会自动关闭程序

    google::ShutdownGoogleLogging();
    return 0;
}
