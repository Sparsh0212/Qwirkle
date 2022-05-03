#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <sstream>
#include <iostream>
#include <fstream>


class Game {
public:
	Game();
	~Game();
	void InitializeUI();
	void StartGameloop(std::string);
	void StartGameloop();
	void SaveGame();
	std::string LoadGame(std::string fName);

private:
	LinkedList tile_bag;
	Board board;
	Player players[4];
	int initial_row;
	int initial_col;
	int n; //Number of Players
	int temp;
	

	void InitiateTileBag();
	void InitiatePlayersUI();
	void InitiateHands();
	bool IsEnd();
	bool HandleUserInput(Player& player, std::string input);
	void NextRound(Player& pCurrent);
	bool Place(Player& player, Tile t, Row r, Col c);
	bool UpdateScore(Player& player, Row r, Col c);
	bool IsValidPlacement(Tile t, Row r, Col c);

	
};

#endif
