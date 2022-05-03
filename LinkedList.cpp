
#include "LinkedList.h"
#include <iostream>
#include <stdexcept>

LinkedList::LinkedList()
{
    /*Initalisation of the linked
    list*/
    head = nullptr;
}

LinkedList::LinkedList(LinkedList &other)
{
    /*Copy Constructor*/
    head = nullptr;
    for (int i = 0; i < other.getSize(); i++)
    {
        Tile *tile = new Tile(*other.getTile(i));
        addBack(tile);
        
    }
}

LinkedList::~LinkedList()
{
    /*Destroyer*/
    clear();
}

int LinkedList::getSize()
{
    /*Gets the total size of the linked list*/
    int count = 0;
    Node *current = this->head;
    while (current != nullptr)
    {
        current = current->next;
        count += 1;
    }
    return count;
}

Tile *LinkedList::getTile(int index)
{
    /*Gets a tile within the list*/
    Tile *t = nullptr;
    int counter = 0;
    Node *current = head;
    if (index >= 0 && index < getSize())
    {
        while (counter < index)
        {
            ++counter;
            current = current->next;
        }
        t = current->tile;
    }
    return t;
}

void LinkedList::addBack(Tile *addTile)
{
    /*Adds a node to the end of the list*/
    Node *newNode = new Node(addTile, nullptr);

    Node *current = head;
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::removeFront()
{
    /*Removes an element to the front of the 
    list used for drawing tiles from the bag*/
    if (head != nullptr)
    {
        Node *removeNode = head;
        head = head->next;

        delete removeNode->tile;
        delete removeNode;
    }
    else
    {
        throw new std::runtime_error("No tiles to delete");
    }
}

void LinkedList::removeBack()
{
    /*Removes an element from the back
    of the list*/
    if (this->head == nullptr)
        return;

    if (this->head->next == nullptr)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }

    Node *prev = this->head;
    Node *cur = this->head->next;

    while (cur->next != nullptr)
    {
        prev = prev->next;
        cur = cur->next;
    }

    prev->next = nullptr;
    delete cur;
    return;
}

void LinkedList::removeIndex(int index)
{
    /*Removes an element from a specific point
    in the list*/
    if (index < 0 || index >= this->getSize())
        return;

    if (index == 0)
    {
        return this->removeFront();
    }

    if (index == this->getSize() - 1)
    {
        return this->removeBack();
    }

    /*Third Case: Middle.*/

    Node *prev = this->head;
    Node *cur = this->head->next;
    Node *next = this->head->next->next;

    int cur_idx = 1;

    while (next != nullptr)
    {

        if (cur_idx == index)
        {
            prev->next = next;
            delete cur;
            return;
        }
        else
        {
            cur_idx += 1;
            prev = prev->next;
            next = next->next;
            cur = cur->next;
        }
    }

    return;
}

void LinkedList::clear()
{
    /*Removes an element from the list
    as long as their is one to remove*/
    while (head != nullptr)
    {
        removeFront();
    }
}

int LinkedList::findTile(Tile *t)
{
    /*Finds a specific tile within the list*/
    /*Return -1 if not found.*/

    Node *current = head;
    int index = 0;

    while (current != nullptr)
    {

        if (t->colour == current->tile->colour && t->shape 
        == current->tile->shape)
        {
            return index;
        }
        else
        {
            current = current->next;
            index += 1;
        }
    }

    return -1;
}

bool LinkedList::search(Tile *t)
{/*Finds a tile through its location in the list*/
    return this->findTile(t) != -1;
}

void LinkedList::Display()
{
    /*Displays the contents of the list*/
    Node *current = head;
    while (current->next != nullptr)
    {
        std::cout << *current->tile << " ";
        current = current->next;
    }
    std::cout << *current->tile << std::endl;
}

void LinkedList::displayOutput(std::ofstream &file)
{
    /*Output used for saving*/
    Node *current = head;
    while (current->next != nullptr)
    {
        file << *current->tile << ",";
        current = current->next;
    }
    file << *current->tile << std::endl;
}
