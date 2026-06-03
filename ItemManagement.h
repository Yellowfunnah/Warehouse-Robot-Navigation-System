#pragma once
#include <iostream>
#include <string>
using namespace std;

struct ItemNode
{
    string itemID;
    string itemName;
    string location;

    ItemNode* left;
    ItemNode* right;
};

class ItemManagement
{
private:
    int countNodes(ItemNode* node);
    ItemNode* root;

    ItemNode* insert(ItemNode* node, string id, string name, string location);
    ItemNode* search(ItemNode* node, string id);
    ItemNode* deleteNode(ItemNode* node, string id);
    ItemNode* findMin(ItemNode* node);
    void displayInOrder(ItemNode* node);

public:
    int getTotalItems();
    ItemManagement();

    bool idExists(string id);

    void insertItem(string id, string name, string location);
    void searchItem(string id);
    void updateItem(string id, string newName, string newLocation);
    void deleteItem(string id);
    void displayItems();
};