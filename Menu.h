#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include <string>

class Menu {

public:
	Menu();
	~Menu();

private:
	int ShowMainPage();
	void ShowCreditPage();
	void PageControl();

	
	Game game;
};

#endif