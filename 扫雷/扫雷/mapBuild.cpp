#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<ctime>
#include<random>
#include"mapBuild.h"
#include"playerInformation.h"

mapState mapBuild::getMapDifficulty(gameDifficulty diff) {//对应难度映射
	switch (diff) {
	case gameDifficulty::EASY:
		return { 10,5 };
	case gameDifficulty::MEDIUM:
		return { 15,50 };
	case gameDifficulty::HARD:
		return { 20,150 };
	default:
		std::cout<<"无效的游戏难度！";
		return { 10,5 };
	}
}
std::vector<std::vector<CellInfo>>mapBuild::emptyMap(int size) {//创建空地图
	std::vector<std::vector<CellInfo>> emptyMap(size, std::vector<CellInfo>(size));
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			emptyMap[x][y].logicType = CellType::EMPTY;
			emptyMap[x][y].aroundBombCount = 0;
			emptyMap[x][y].originalType = CellType::EMPTY;
			emptyMap[x][y].ifOpen = CellShowType::UNOPEN;
			emptyMap[x][y].areaID = -1;
		}
	}
	return emptyMap;
}
void mapBuild::setBomb(std::vector<std::vector<CellInfo>>& map, int bombCount) {//布置炸弹
	static bool isSeeded = false;
	if (!isSeeded) {
		srand(static_cast<unsigned int>(time(0)));
		isSeeded = true;
	}
	int mapSize = map.size();
	if (mapSize == 0 || bombCount <= 0)return;
	while (bombCount-- > 0) {
		int rand_x = rand() % mapSize; int rand_y = rand() % mapSize;
		if (map[rand_x][rand_y].logicType== CellType::EMPTY) {
			map[rand_x][rand_y].logicType = CellType::BOMB;
		}
		else {
			bombCount++;
		}
	}

}
void mapBuild::printfMap(const std::vector<std::vector<CellInfo>>& map) {//打印地图
	int size = map.size();
	if (map.empty()) {
		std::cout << "地图打印失败\n";
		return;
	}
	information mapInfor;
	mapInfor.doPrintfInfor(map);
	for (int judge = 1; judge <= 3; judge++) {
		for (int y = 0; y < size; y++) {
			if (judge == 1) {
				char letter = 'A' + y;
				std::cout << letter << " ";
			}
			else if (judge == 2) {
				std::cout << "| ";
			}
			else if(judge==3)
			{
				std::cout << "v ";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (map[x][y].ifOpen == CellShowType::OPEN) {
				if (map[x][y].logicType == CellType::BOMB) {
					std::cout << "X" << " ";
				}
				else {
					std::cout << map[x][y].aroundBombCount << " ";
				}
			}
			else{
				if (map[x][y].logicType == CellType::MARK) {
					std::cout << "P" << " ";
				}
				else {
					std::cout << "*" << " ";
				}
			}
			
		}
		std::cout <<" <-" << x + 1 << "  \n";
	}
}
std::vector<std::vector<CellInfo>>mapBuild::buildMap(gameDifficulty diff) {
	try {
		mapState config = getMapDifficulty(diff);
		auto map = emptyMap(config.size);
		setBomb(map, config.bombCount);
		findBombCount(map);
		return map;
	}
	catch (...) {
		std::cout << "地图创建失败";
		return{};
	}
}
bool mapBuild::CheckSide(std::vector<std::vector<CellInfo>>& map, int x, int y){
	int size = map.size();
	return x >= 0 && x < size && y >= 0 && y < size;
}
void mapBuild::findBombCount(std::vector<std::vector<CellInfo>>&map) {
	int size = map.size();
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (map[x][y].logicType== CellType::BOMB) {
				continue;
			}
			int bombCount = 0;
			for (int dx = -1; dx <= 1; dx++) {
				for (int dy = -1; dy <= 1; dy++) {
					if (dx == 0 && dy == 0)continue;
					int nx = x + dx;
					int ny = y + dy;
					if (CheckSide(map,nx,ny)&&map[nx][ny].logicType == CellType::BOMB) {
						bombCount++;
					}
				}
			}
			map[x][y].aroundBombCount = bombCount;
		}
	}
}