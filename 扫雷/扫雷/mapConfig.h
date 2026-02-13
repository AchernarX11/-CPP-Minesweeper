#pragma once
#ifndef MAP_CONFIG
#define MAP_CONFIG
enum class gameDifficulty//地图难度
{
	EASY,
	MEDIUM,
	HARD
};
struct mapState//地图属性
{
	int size;//地图大小
	int bombCount;//炸弹数量
};
enum class CellType {//设置单元格状态
	BOMB,
	EMPTY,
	MARK
};
enum class CellShowType {
	OPEN,
	UNOPEN
};
struct CellInfo
{
	CellType logicType;
	CellType originalType;
	int aroundBombCount;
	CellShowType ifOpen;
	int areaID;
};
#endif // !MAP_CONFIG
