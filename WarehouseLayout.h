#ifndef WAREHOUSELAYOUT_H
#define WAREHOUSELAYOUT_H

#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
    string name;
    string type;
    string itemStored;

    TreeNode* firstChild;
    TreeNode* nextSibling;

    TreeNode(string nodeName, string nodeType, string item = "")
    {
        name = nodeName;
        type = nodeType;
        itemStored = item;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

class WarehouseLayout
{
private:
    TreeNode* root;

    void printTree(TreeNode* node, int depth);
    TreeNode* searchNode(TreeNode* node, const string& target);
    void addChild(TreeNode* parent, TreeNode* child);
    void preOrderTraversal(TreeNode* node);
    bool findPath(TreeNode* node, const string& target, TreeNode* path[], int& pathLen);
    void deleteTree(TreeNode* node);

public:
    WarehouseLayout();
    ~WarehouseLayout();

    void buildSampleLayout();
    void displayLayout();
    void addZone();
    void addAisle();
    void addShelf();
    void searchLocation();
    void showPathToLocation();
    void traverseWarehouse();
};

#endif