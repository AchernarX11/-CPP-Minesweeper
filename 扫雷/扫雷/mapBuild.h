#pragma once
#ifndef MAP_BUILD_H
#define MAP_BUILD_H
#include"mapConfig.h"
#include<vector>

class mapBuild {
private:
	mapState getMapDifficulty(gameDifficulty diff);//映射地图难度
	std::vector<std::vector<CellInfo>>emptyMap(int size);//创建空地图
	void setBomb(std::vector<std::vector<CellInfo>>& map, int bombCount);//设置炸弹
	void findBombCount(std::vector<std::vector<CellInfo>>&map);//查看附近炸弹数
	bool CheckSide(std::vector<std::vector<CellInfo>>& map,int x,int y);
public:
	void printfMap(const std::vector<std::vector<CellInfo>>& map);//打印地图
	std::vector<std::vector<CellInfo>>buildMap(gameDifficulty diff);//建立地图入口
};
#endif