#pragma once
#ifndef PLAYER_INFORMATION_H
#define	PLAYER_IFFORMATION_H
#include"mapConfig.h"
#include<vector>
struct gameInfor
{
	int	nowBombCount;
	int score;
	int markCount;
	int openCount;
};
class information {  
private:
	std::vector<std::vector<CellInfo>>gameMap; 
	void emptyMapInfor(const std::vector<std::vector<CellInfo>>& map);
	void saveInfor(const std::vector<std::vector<CellInfo>>& map);
	void printfInfor(const std::vector<std::vector<CellInfo>>& map);
	gameInfor Infor;
public:
	void doPrintfInfor(const std::vector<std::vector<CellInfo>>& map) { printfInfor(map); };
};
#endif // !PLAY_INFORMATION_H
