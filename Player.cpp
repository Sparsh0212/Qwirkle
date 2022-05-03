#include "Player.h"
#include "Colors.h"
#include <iostream>


Player::Player()
{
    this->hand = new LinkedList();
    this->player_score = 0;
    this->player_name = "Unitialized";
}

Player::Player(std::string name)
{
    this->hand = new LinkedList();
    this->player_name = name;
    this->player_score = 0;
}

std::string Player::GetPlayerName()
{
    return player_name;
}
void Player::InitialHand(LinkedList* list)
{
    delete hand;
    hand = new LinkedList(*list);
}
void Player::ShowHand()
{
    setTextColor(GREEN_TXT);
    hand->Display();
    resetTextColor(RESET_COLOR);
}
LinkedList *Player::GetHand()
{
    return hand;
}

float Player::GetScore()
{
    return this->player_score;
}

void Player::SetScore(float score)
{
    this->player_score = score;
}

bool Player::HasTile(Tile& tile)
{
   return this->hand->search(&tile);
}

