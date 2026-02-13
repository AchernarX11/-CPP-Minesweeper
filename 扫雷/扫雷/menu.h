#pragma once
#ifndef MENU_H
#define MENU_H

enum menuState {
	EXIT = 0,
	MAIN_MENU,
	TXT,
	DIFFICULTY_CHOISE,
	TXT_ONE,
	TXT_TOW,
	TXT_THREE
};
void doClearScreen();
void doWaitEnter();
void doShowMainMenu();
void doShowTxt();
void doShowDifficultyMenu();
void doShowTxtOne();
void doShowTxtTow();
void doShowTxtThree();
#endif

