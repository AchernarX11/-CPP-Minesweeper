#pragma once
#ifndef GAME_H
#define GAME_H
enum inputState {
	INPUT='>',
	MARK='p'
};
class gameing {
private:
	std::vector<std::vector<CellInfo>>gameMap;
	void input();
	void gameControls(int x, int y, inputState op);
	bool winCheck();
	void openAren(std::vector<std::vector<CellInfo>>& map, int x, int y);

public:
	void runGame(gameDifficulty diff);
};
#endif // !GAME_H
