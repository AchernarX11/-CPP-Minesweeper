#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"menu.h"
#include"gameManager.h"
class allMenu {
	void clearScreen();
	void waitEnter();
	void showMainMenu();
	void showTxt();
	void showDifficultyMenu();
	void showTxtOne();
	void showTxtTow();
	void showTxtThree();
public:
	void doClearScreen() { clearScreen(); };
	void doWaitEnter() { waitEnter(); };
	void doShowMainMenu() { showMainMenu(); };
	void doShowDifficultyMenu() { showDifficultyMenu(); };
	void doShowTxt() { showTxt(); };
	void doShowTxtOne() { showTxtOne(); };
	void doShowTxtTow() { showTxtTow(); };
	void doShowTxtThree() { showTxtThree(); };
};
void allMenu::clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
void allMenu::waitEnter() {
	std::cout << "输入任意继续...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	std::cin.get();
}
void allMenu::showMainMenu() {
	clearScreen();
	std::cout << "**********************************\n";
	std::cout << "*              扫雷              *\n";
	std::cout << "**********************************\n";
	std::cout << "*           1.开始游戏           *\n";
	std::cout << "**********************************\n";
	std::cout << "*           2.游戏说明           *\n";
	std::cout << "**********************************\n";
	std::cout << "*           0.退    出           *\n";
	std::cout << "**********************************\n";
	std::cout << "请输入数字选择 > ";

}
void allMenu::showTxt() {
	clearScreen();
	std::cout << "**********************************\n";
	std::cout << "*            说    明            *\n";
	std::cout << "**********************************\n";
	std::cout << "*           1.游戏说明           *\n";
	std::cout << "**********************************\n";
	std::cout << "*           2.游戏规则           *\n";
	std::cout << "**********************************\n";
	std::cout << "*           3.作者声名           *\n";
	std::cout << "**********************************\n";
	std::cout << "*           0.返    回           *\n";
	std::cout << "**********************************\n";
	std::cout << "请输入数字选择 > ";
}
void allMenu::showTxtOne() {
	std::cout << "**********************************\n";
	std::cout << "*            游戏说明            *\n";
	std::cout << "**********************************\n";
	std::cout << "*                                *\n";
	std::cout << "*    本游戏仿照经典扫雷游戏，目标*\n";
	std::cout << "*是在不踩到地雷的情况下，将安全区*\n";
	std::cout << "*全部点开，给地雷打上标记，本游戏*\n";
	std::cout << "*将全程才用键盘输入方式进行游玩  *\n";
	std::cout << "*                                *\n";
	std::cout << "**********************************\n";
	std::cout << "*   输入0返回                    *\n";
	std::cout << "**********************************\n";
	std::cout << "请输入数字选择 > ";


}
void allMenu::showTxtTow() {
	std::cout << "****************************************\n";
	std::cout << "*               规则说明               *\n";
	std::cout << "****************************************\n";
	std::cout << "*                                      *\n";
	std::cout << "* 1.游戏会在地图中随机生成地雷         *\n";
	std::cout << "* 2.数字代表附近8个格子的地雷数量      *\n";
	std::cout << "* 3.选中地雷即爆炸，扫雷失败           *\n";
	std::cout << "* 4.将所有安全区点开即获胜             *\n";
	std::cout << "* 5.标记功能可标出怀疑地雷，防止误操作 *\n";
	std::cout << "*                                      *\n";
	std::cout << "* 输入格式:                            *\n";
	std::cout << "* > x y → 翻开(x,y)位置                *\n";
	std::cout << "* * x y → 标记/取消标记(x,y)为炸弹     *\n";
	std::cout << "*                                      *\n";
	std::cout << "****************************************\n";
	std::cout << "*   输入0返回                          *\n";
	std::cout << "****************************************\n";
	std::cout << "请输入数字选择 > ";
}
void allMenu::showTxtThree() {
	std::cout << "**********************************\n";
	std::cout << "*            作者声名            *\n";
	std::cout << "**********************************\n";
	std::cout << "*                                *\n";
	std::cout << "*    本扫雷游戏由个人使用cpp语言 *\n";
	std::cout << "*独立开发完成,感谢你的游玩测试， *\n";
	std::cout << "*欢迎找bug                       *\n";
	std::cout << "*                                *\n";
	std::cout << "*作者：小11                      *\n";
	std::cout << "*联系方式：3445229764@qq.com     *\n";
	std::cout << "*                                *\n";
	std::cout << "**********************************\n";
	std::cout << "*   输入0返回                    *\n";
	std::cout << "**********************************\n";
	std::cout << "请输入数字选择 > ";
}
void allMenu::showDifficultyMenu()
{
	clearScreen();
	std::cout << "**********************************\n";
	std::cout << "*            困难选择            *\n";
	std::cout << "**********************************\n";
	std::cout << "*           1.简    单           *\n";
	std::cout << "**********************************\n";
	std::cout << "*           2.一    般           *\n";
	std::cout << "**********************************\n";
	std::cout << "*           3.困    难           *\n";
	std::cout << "**********************************\n";
	std::cout << "*           0.返    回           *\n";
	std::cout << "**********************************\n";
	std::cout << "请输入数字选择 > ";

}
allMenu menu;
void doClearScreen() { menu.doClearScreen(); }
void doWaitEnter() { menu.doWaitEnter(); }
void doShowMainMenu() { menu.doShowMainMenu(); }
void doShowTxt() { menu.doShowTxt(); }
void doShowDifficultyMenu() { menu.doShowDifficultyMenu(); }
void doShowTxtOne() { menu.doShowTxtOne(); }
void doShowTxtTow() { menu.doShowTxtTow(); }
void doShowTxtThree() { menu.doShowTxtThree(); }