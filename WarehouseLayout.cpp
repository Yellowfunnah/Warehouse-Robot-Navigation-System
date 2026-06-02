#include "WarehouseLayout.h"

WarehouseLayout::WarehouseLayout()
{
    root = new TreeNode("Warehouse", "root");
}

WarehouseLayout::~WarehouseLayout()
{
    deleteTree(root);
}

void WarehouseLayout::deleteTree(TreeNode* node)
{
    if (node == nullptr)
        return;
    deleteTree(node->firstChild);
    deleteTree(node->nextSibling);
    delete node;
}

void WarehouseLayout::addChild(TreeNode* parent, TreeNode* child)
{
    if (parent->firstChild == nullptr)
    {
        parent->firstChild = child;
    }
    else
    {
        TreeNode* current = parent->firstChild;
        while (current->nextSibling != nullptr)
            current = current->nextSibling;
        current->nextSibling = child;
    }
}

TreeNode* WarehouseLayout::searchNode(TreeNode* node, const string& target)
{
    if (node == nullptr)
        return nullptr;
    if (node->name == target)
        return node;
    TreeNode* found = searchNode(node->firstChild, target);
    if (found != nullptr)
        return found;
    return searchNode(node->nextSibling, target);
}

void WarehouseLayout::printTree(TreeNode* node, int depth)
{
    if (node == nullptr)
        return;

    for (int i = 0; i < depth; i++)
        cout << "  ";

    if (depth == 0)
        cout << "[WAREHOUSE] " << node->name << endl;
    else if (node->type == "zone")
        cout << "|-- [ZONE]  " << node->name << endl;
    else if (node->type == "aisle")
        cout << "|---- [AISLE] " << node->name << endl;
    else if (node->type == "shelf")
    {
        cout << "|------ [SHELF] " << node->name;
        if (!node->itemStored.empty())
            cout << "  (Item: " << node->itemStored << ")";
        cout << endl;
    }

    printTree(node->firstChild, depth + 1);
    printTree(node->nextSibling, depth);
}

void WarehouseLayout::preOrderTraversal(TreeNode* node)
{
    if (node == nullptr)
        return;

    cout << "  -> [" << node->type << "] " << node->name;
    if (!node->itemStored.empty())
        cout << " | Item: " << node->itemStored;
    cout << endl;

    preOrderTraversal(node->firstChild);
    preOrderTraversal(node->nextSibling);
}

bool WarehouseLayout::findPath(TreeNode* node, const string& target,
    TreeNode* path[], int& pathLen)
{
    if (node == nullptr)
        return false;

    path[pathLen] = node;
    pathLen++;

    if (node->name == target)
        return true;

    if (findPath(node->firstChild, target, path, pathLen))
        return true;

    if (node != root && findPath(node->nextSibling, target, path, pathLen))
        return true;

    pathLen--;
    return false;
}

void WarehouseLayout::buildSampleLayout()
{
    TreeNode* zoneA = new TreeNode("Zone A", "zone");
    TreeNode* aisleA1 = new TreeNode("Aisle A1", "aisle");
    addChild(aisleA1, new TreeNode("Shelf A1-1", "shelf", "Laptop"));
    addChild(aisleA1, new TreeNode("Shelf A1-2", "shelf", "Keyboard"));
    TreeNode* aisleA2 = new TreeNode("Aisle A2", "aisle");
    addChild(aisleA2, new TreeNode("Shelf A2-1", "shelf", "Monitor"));
    addChild(aisleA2, new TreeNode("Shelf A2-2", "shelf", "Mouse"));
    addChild(zoneA, aisleA1);
    addChild(zoneA, aisleA2);

    TreeNode* zoneB = new TreeNode("Zone B", "zone");
    TreeNode* aisleB1 = new TreeNode("Aisle B1", "aisle");
    addChild(aisleB1, new TreeNode("Shelf B1-1", "shelf", "Headphones"));
    addChild(aisleB1, new TreeNode("Shelf B1-2", "shelf", "Webcam"));
    TreeNode* aisleB2 = new TreeNode("Aisle B2", "aisle");
    addChild(aisleB2, new TreeNode("Shelf B2-1", "shelf", "USB Hub"));
    addChild(zoneB, aisleB1);
    addChild(zoneB, aisleB2);

    TreeNode* zoneC = new TreeNode("Zone C", "zone");
    TreeNode* aisleC1 = new TreeNode("Aisle C1", "aisle");
    addChild(aisleC1, new TreeNode("Shelf C1-1", "shelf", "Desk Lamp"));
    addChild(aisleC1, new TreeNode("Shelf C1-2", "shelf", "Chair"));
    addChild(zoneC, aisleC1);

    addChild(root, zoneA);
    addChild(root, zoneB);
    addChild(root, zoneC);

    cout << "\nSample warehouse layout built successfully!" << endl;
}

void WarehouseLayout::displayLayout()
{
    cout << "\n===== WAREHOUSE LAYOUT =====" << endl;
    printTree(root, 0);
    cout << "=============================" << endl;
}

void WarehouseLayout::addZone()
{
    string zoneName;
    cout << "\nEnter Zone Name (e.g. Zone D): ";
    cin.ignore();
    getline(cin, zoneName);

    if (searchNode(root, zoneName) != nullptr)
    {
        cout << "Error: '" << zoneName << "' already exists!" << endl;
        return;
    }

    addChild(root, new TreeNode(zoneName, "zone"));
    cout << "Zone '" << zoneName << "' added successfully!" << endl;
}

void WarehouseLayout::addAisle()
{
    string zoneName, aisleName;
    cout << "\nEnter Zone Name to add Aisle to: ";
    cin.ignore();
    getline(cin, zoneName);

    TreeNode* zone = searchNode(root, zoneName);
    if (zone == nullptr || zone->type != "zone")
    {
        cout << "Error: Zone '" << zoneName << "' not found!" << endl;
        return;
    }

    cout << "Enter Aisle Name: ";
    getline(cin, aisleName);

    if (searchNode(root, aisleName) != nullptr)
    {
        cout << "Error: '" << aisleName << "' already exists!" << endl;
        return;
    }

    addChild(zone, new TreeNode(aisleName, "aisle"));
    cout << "Aisle '" << aisleName << "' added under '" << zoneName << "'!" << endl;
}

void WarehouseLayout::addShelf()
{
    string aisleName, shelfName, itemName;
    cout << "\nEnter Aisle Name to add Shelf to: ";
    cin.ignore();
    getline(cin, aisleName);

    TreeNode* aisle = searchNode(root, aisleName);
    if (aisle == nullptr || aisle->type != "aisle")
    {
        cout << "Error: Aisle '" << aisleName << "' not found!" << endl;
        return;
    }

    cout << "Enter Shelf Name: ";
    getline(cin, shelfName);

    if (searchNode(root, shelfName) != nullptr)
    {
        cout << "Error: '" << shelfName << "' already exists!" << endl;
        return;
    }

    cout << "Enter Item Stored (or leave blank): ";
    getline(cin, itemName);

    addChild(aisle, new TreeNode(shelfName, "shelf", itemName));
    cout << "Shelf '" << shelfName << "' added under '" << aisleName << "'!" << endl;
}

void WarehouseLayout::searchLocation()
{
    string target;
    cout << "\nEnter Location Name to Search: ";
    cin.ignore();
    getline(cin, target);

    TreeNode* found = searchNode(root, target);
    if (found == nullptr)
    {
        cout << "Location '" << target << "' not found." << endl;
        return;
    }

    cout << "\n--- Location Found ---" << endl;
    cout << "Name : " << found->name << endl;
    cout << "Type : " << found->type << endl;
    if (!found->itemStored.empty())
        cout << "Item : " << found->itemStored << endl;
    cout << "----------------------" << endl;
}

void WarehouseLayout::showPathToLocation()
{
    string target;
    cout << "\nEnter Destination Name: ";
    cin.ignore();
    getline(cin, target);

    TreeNode* path[50];
    int pathLen = 0;

    if (!findPath(root, target, path, pathLen))
    {
        cout << "Location '" << target << "' not found!" << endl;
        return;
    }

    cout << "\n=== Navigation Route to '" << target << "' ===" << endl;
    for (int i = 0; i < pathLen; i++)
    {
        cout << "[" << path[i]->type << "] " << path[i]->name;
        if (i < pathLen - 1)
            cout << " --> ";
    }
    cout << endl;
    cout << "Total steps: " << (pathLen - 1) << endl;
    cout << "==========================================" << endl;
}

void WarehouseLayout::traverseWarehouse()
{
    cout << "\n=== Pre-Order Traversal of Warehouse ===" << endl;
    preOrderTraversal(root->firstChild);
    cout << "=========================================" << endl;
}