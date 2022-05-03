
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include <fstream>

class LinkedList
{
public:
   LinkedList();
   ~LinkedList();
   LinkedList(LinkedList& other);
    
   // Gets the Size of the List
   int getSize();

   // Returns the tile at given index in the list
   Tile* getTile(int index);

   // Adds tile to the end of the list
   void addBack(Tile *tile);

   // Removes the first element present in the list
   void removeFront();

   // Removes the last element present in the list
   void removeBack();

   // Removes the value at the specific index
   void removeIndex(int index);

   // Returns the index of the tile where it is stored in the list
   int findTile(Tile* t);
   
   // checks if tile is present in the list
   bool search(Tile* tile);

// Clears the list
   void clear();

// Display the content of the list
   void Display();

   void displayOutput(std::ofstream&);

private:
   Node *head;
};

#endif // ASSIGN2_LINKEDLIST_H
