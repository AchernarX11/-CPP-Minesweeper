#define _CRT_SECURE_NO_WARNINGS 1
#include"playerInformation.h"
#include"mapConfig.h"
#include<iostream>
#include"mapBuild.h"
#include<vector>

void information::emptyMapInfor(const std::vector<std::vector<CellInfo>>& map) {
	int size = map.size();
	Infor.nowBombCount = 0;
	Infor.markCount = 0;  
	Infor.openCount = 0;
	Infor.score = 0;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (map[x][y].logicType == CellType::BOMB) {
				Infor.nowBombCount++;
			}
		}
	}
}
void information::saveInfor(const std::vector<std::vector<CellInfo>>& map) {
	int size = map.size(); 
	Infor.markCount = 0;
	Infor.openCount = 0;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (map[x][y].ifOpen == CellShowType::OPEN) {
				Infor.openCount++;
			}
			if (map[x][y].logicType == CellType::MARK) {
				Infor.markCount++;
			}
		}
	}
}
void information::printfInfor(const std::vector<std::vector<CellInfo>>& map) {
	emptyMapInfor(map);
	saveInfor(map);
	std::cout << "***************************************\n";
	std::cout << "*地图雷数 * 插旗数量 * 安全区发现数量 * \n";
	std::cout << "***************************************\n";
	std::cout << "*    " << Infor.nowBombCount << "    *    " 
			  << Infor.markCount << "     *        " 
			  << Infor.openCount << "       *\n";
	std::cout << "***************************************\n";
}