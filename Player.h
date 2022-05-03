#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include "LinkedList.h"


class Player{

public:
    Player();
    Player(std::string name);
    std::string GetPlayerName();
    void InitialHand(LinkedList* list);
    void ShowHand();    
    LinkedList* GetHand();
    float GetScore();
    void SetScore(float score);
    bool HasTile(Tile& tile);
    


private:
    std::string player_name;
    float player_score;
    LinkedList* hand;
};

#endif // Player_H