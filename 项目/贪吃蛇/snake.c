#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"

void SetPos(short x, short y)
{
	//获得标准输出设备的句柄
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标的位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(houtput, pos);
}

void WelconetoGame()
{
	SetPos(40, 14);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");

	SetPos(42, 20);
	system("pause");

	//清理屏幕
	system("cls");

	SetPos(25, 14);
	wprintf(L"用 ↑. ↓. ←. →来控制蛇的移动，按F3加速，F4减速\n");
	SetPos(25, 15);
	wprintf(L"加速能够得到更高得分数\n");

	SetPos(42, 20);
	system("pause");

	//清理屏幕
	system("cls");
}


//函数的声明
void GameStart(pSnake ps)
{
	//0. 先设置窗口的大小
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	//隐藏光标操作
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false;//隐藏控制台光标
	SetConsoleCursorInfo(houtput, &CursorInfo);//设置控制台光标状态
	
	//1. 打印欢迎界面
	WelconetoGame();
	//2. 功能介绍
	//3. 绘制地图
	
	//4. 创建蛇
	//5. 创建食物
	//6. 设置游戏的相关信息
}