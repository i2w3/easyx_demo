#include <conio.h>
#include <stdio.h>

#include "../easyx240225/include/graphics.h"		// 引用图形库头文件

int main()
{
    printf("Hello, world\n");
    initgraph(640, 480);	// 创建绘图窗口，大小为 640x480 像素
    circle(200, 200, 100);	// 画圆，圆心(200, 200)，半径 100
    _getch();				// 按任意键继续
    closegraph();			// 关闭绘图窗口
    return 0;
}
