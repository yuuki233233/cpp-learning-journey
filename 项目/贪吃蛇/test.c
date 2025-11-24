#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"

//完成的是游戏的测试逻辑
void test()
{
	//创建贪吃蛇
	Snake snake = { 0 };

	//初始化游戏
	//0. 光标隐藏
	//1. 打印欢迎界面
	//2. 功能介绍
	//3. 绘制地图
	//4. 创建蛇
	//5. 创建食物
	//6. 设置游戏的相关信息
	GameStart(&snake);

	//运行游戏
	//GameRun();

	//结束游戏 - 善后工作
	//GameEend();
}

int main()
{
	//设置适配本地环境
	setlocale(LC_ALL, "");

	test();
	return 0;
}