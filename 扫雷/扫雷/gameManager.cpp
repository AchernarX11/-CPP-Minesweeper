#define _CRT_SECURE_NO_WARNINGS 1
#define NT std::endl
#include<iostream>
#include"menu.h"
#include"mapBuild.h"
#include"game.h"
#include<vector>
void RUN(gameDifficulty(diff)) {
	gameing game;
	game.runGame(diff);
}
int Launch() {
	menuState curres = MAIN_MENU;
	int choise;
	while (true) {
		switch (curres) {
		case MAIN_MENU:
			doClearScreen();
			doShowMainMenu();
			break;
		case TXT:
			doClearScreen();
			doShowTxt();
			break;
		case DIFFICULTY_CHOISE:
			doClearScreen();
			doShowDifficultyMenu();
			break;
		case TXT_ONE:
			doClearScreen();
			doShowTxtOne();
			break;
		case TXT_TOW:
			doClearScreen();
			doShowTxtTow();
			break;
		case TXT_THREE:
			doClearScreen();
			doShowTxtThree();
			break;
		case EXIT:
			doClearScreen();
			return 0;
		}
		if (!(std::cin >> choise)) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "·Ç·¨ÊäÈë\n";
			doWaitEnter();
			continue;
		}
		switch (curres) {
		case MAIN_MENU:
			if (choise == 0) curres = EXIT;
			else if (choise == 1)curres = DIFFICULTY_CHOISE;
			else if (choise == 2) curres = TXT;
			break;
		case TXT:
			if (choise == 0)curres = MAIN_MENU;
			else if (choise == 1)curres = TXT_ONE;
			else if (choise == 2)curres = TXT_TOW;
			else if (choise == 3)curres = TXT_THREE;
			break;
		case DIFFICULTY_CHOISE:
			if (choise == 1) {
				RUN(gameDifficulty::EASY);
				curres = MAIN_MENU;
				break;
			}
			else if (choise == 2) {
				RUN(gameDifficulty::MEDIUM);
				curres = MAIN_MENU;
				break;
			}
			else if (choise == 3) {
				RUN(gameDifficulty::HARD);
				curres = MAIN_MENU;
				break;
			}
			else if (choise == 0) {
				curres = MAIN_MENU;
				break;
			}
		case TXT_ONE:
			if (choise == 0)curres = TXT;
			break;
		case TXT_TOW:
			if (choise == 0)curres = TXT;
			break;
		case TXT_THREE:
			if (choise == 0)curres = TXT;
			break;
		}
	}
}
