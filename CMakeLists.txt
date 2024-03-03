cmake_minimum_required(VERSION 3.27)
project(MyDino LANGUAGES CXX VERSION 0.0.1)
# 设置CXX标准为CXX 17
set(CMAKE_CXX_STANDARD 17)
# 要求编译器必须支持CXX 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 如果编译器不支持 CXX 17，CMake 配置将会失败。
# 可以帮助保证项目的可移植性和一致性，确保在不同的开发环境中都能按照预期的标准进行编译。

# 引入头文件路径
include_directories(./easyx240225/include ./inc)
link_directories(./easyx240225/lib64)
# 获取某目录下的所有源文件
aux_source_directory(./src SRC)
# 生成可执行文件
add_executable(MyDino ${SRC})
add_compile_options(-Wall)
target_link_libraries(MyDino easyx)