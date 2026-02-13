#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"mapBuild.h"
#include"game.h"
#include"menu.h"
#include<limits>
#include<vector>
mapBuild mapConttrols;
void gameing::openAren(std::vector<std::vector<CellInfo>>& map, int x, int y) {
	int size = map.size();
	if (x < 0 || x >= size || y < 0 || y >= size || map[x][y].ifOpen == CellShowType::OPEN || map[x][y].logicType == CellType::BOMB||map[x][y].logicType==CellType::MARK) {
		return;
	}
	map[x][y].ifOpen = CellShowType::OPEN;
	if (map[x][y].aroundBombCount != 0) {
		return;
	}

	openAren(map, x - 1, y-1);
	openAren(map, x - 1, y);
	openAren(map, x - 1, y + 1);
	openAren(map, x + 1, y + 1);
	openAren(map, x + 1, y - 1);
	openAren(map, x + 1, y);
	openAren(map, x, y + 1);
	openAren(map, x, y - 1);
}
void gameing::gameControls(int x, int y,inputState op) {
	if (op == INPUT) {
		if (gameMap[x][y].logicType == CellType::BOMB) {
			doClearScreen();
			for (auto& row : gameMap) {
				for (auto& cell : row) {
					//if (cell.logicType != cell.originalType) { cell.logicType = cell.originalType; }
					cell.ifOpen = CellShowType::OPEN;
				}
			}
			mapConttrols.printfMap(gameMap);
			std::cout << "踩中地雷，游戏结束\n";
			exit(0);
		}
		if (gameMap[x][y].ifOpen == CellShowType::UNOPEN) {
			openAren(gameMap, x, y);
		}		
	}
	else if (op == MARK) {
		if (gameMap[x][y].ifOpen == CellShowType::OPEN) {
			std::cout << "已打开的格子无法标记\n";
			doWaitEnter();
		}
		else if(gameMap[x][y].logicType==CellType::MARK) {
			gameMap[x][y].logicType = gameMap[x][y].originalType;
			std::cout << "已移除标记\n";
			doWaitEnter();

		}
		else {
			gameMap[x][y].originalType = gameMap[x][y].logicType;
			gameMap[x][y].logicType = CellType::MARK;
			std::cout << "已标记\n";
			doWaitEnter();

		}
	}
}
void gameing::input() {
	char op,Y_leeter;
	int x, y;
	while (true) {
		std::cout << "请输入操作\n";
		std::cin >> op;
		if (op == '0') {
			std::cout << "退出游戏...\n";
			break;
		}
		if (!(std::cin >> Y_leeter >> x)) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "非法操作\n";
			continue;
		}
		y = Y_leeter - 'A'+1;
		x--; y--;
		if (x<0 || x>=gameMap.size() || y<0 || y>=gameMap.size()) {
			std::cout << "超出范围";
			continue;
		}
		if (op == '>') {
			gameControls(x, y, INPUT);
		}
		else if (op == '*') {
			gameControls(x, y, MARK);
		}
		else {
			std::cout << "无效操作，请重新输入\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		doClearScreen();
		mapConttrols.printfMap(gameMap);
		if (winCheck()) {
			doClearScreen();
			std::cout << "恭喜，你赢了！\n";
			mapConttrols.printfMap(gameMap);
			break;
		}
	}
}
bool gameing::winCheck() {
	int size = gameMap.size();
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (gameMap[x][y].logicType == CellType::BOMB && gameMap[x][y].ifOpen == CellShowType::OPEN) {//踩雷
				return false;
			}
			if (gameMap[x][y].logicType == CellType::EMPTY && gameMap[x][y].ifOpen == CellShowType::UNOPEN) {//没开完
				return false;
			}
		}
	}
	return true;
}
void gameing::runGame(gameDifficulty diff) {
	gameMap = mapConttrols.buildMap(diff);
	if (gameMap.empty()) {
		std::cout << "地图初始化失败\n";
		doWaitEnter();
		doClearScreen();
		return;
	}
	doClearScreen();
	mapConttrols.printfMap(gameMap);
	std::cout << "*****************************************\n";
	std::cout << "*                游戏开始               *\n";
	std::cout << "*****************************************\n";
	std::cout << "*   输入格式:                           *\n";
	std::cout << "*      > x y → 翻开(x,y)位置            *\n";
	std::cout << "*      * x y → 标记/取消标记(x,y)为炸弹 *\n";
	std::cout << "*****************************************\n";
	std::cout << "*   0 → 退出游戏                        *\n";
	std::cout << "*****************************************\n";
	input();
	doWaitEnter();
	doClearScreen();
}
