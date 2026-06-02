#include "ItemManagement.h"

ItemManagement::ItemManagement()
{
    root = nullptr;
}

bool ItemManagement::idExists(string id)
{
    return search(root, id) != nullptr;
}

ItemNode* ItemManagement::insert(ItemNode* node, string id, string name, string location)
{
    if (node == nullptr)
    {
        ItemNode* newNode = new ItemNode;
        newNode->itemID = id;
        newNode->itemName = name;
        newNode->location = location;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (id < node->itemID)
        node->left = insert(node->left, id, name, location);
    else if (id > node->itemID)
        node->right = insert(node->right, id, name, location);
    else
        cout << "Item ID already exists.\n";

    return node;
}

void ItemManagement::insertItem(string id, string name, string location)
{
    if (search(root, id) != nullptr)
    {
        cout << "Item ID already exists.\n";
        return;
    }

    root = insert(root, id, name, location);
    cout << "Item inserted successfully.\n";
}

ItemNode* ItemManagement::search(ItemNode* node, string id)
{
    if (node == nullptr || node->itemID == id)
        return node;

    if (id < node->itemID)
        return search(node->left, id);

    return search(node->right, id);
}

void ItemManagement::searchItem(string id)
{
    ItemNode* result = search(root, id);

    if (result == nullptr)
    {
        cout << "Item not found.\n";
    }
    else
    {
        cout << "\nItem Found\n";
        cout << "Item ID   : " << result->itemID << endl;
        cout << "Item Name : " << result->itemName << endl;
        cout << "Location  : " << result->location << endl;
    }
}

void ItemManagement::updateItem(string id, string newName, string newLocation)
{
    ItemNode* result = search(root, id);

    if (result == nullptr)
    {
        cout << "Item not found. Update failed.\n";
    }
    else
    {
        result->itemName = newName;
        result->location = newLocation;
        cout << "Item updated successfully.\n";
    }
}

ItemNode* ItemManagement::findMin(ItemNode* node)
{
    while (node != nullptr && node->left != nullptr)
        node = node->left;

    return node;
}

ItemNode* ItemManagement::deleteNode(ItemNode* node, string id)
{
    if (node == nullptr)
        return node;

    if (id < node->itemID)
        node->left = deleteNode(node->left, id);
    else if (id > node->itemID)
        node->right = deleteNode(node->right, id);
    else
    {
        if (node->left == nullptr)
        {
            ItemNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            ItemNode* temp = node->left;
            delete node;
            return temp;
        }

        ItemNode* temp = findMin(node->right);
        node->itemID = temp->itemID;
        node->itemName = temp->itemName;
        node->location = temp->location;
        node->right = deleteNode(node->right, temp->itemID);
    }

    return node;
}

void ItemManagement::deleteItem(string id)
{
    if (search(root, id) == nullptr)
    {
        cout << "Item not found. Delete failed.\n";
        return;
    }

    root = deleteNode(root, id);
    cout << "Item deleted successfully.\n";
}

void ItemManagement::displayInOrder(ItemNode* node)
{
    if (node == nullptr)
        return;

    displayInOrder(node->left);

    cout << "ID: " << node->itemID
        << " | Name: " << node->itemName
        << " | Location: " << node->location << endl;

    displayInOrder(node->right);
}

void ItemManagement::displayItems()
{
    if (root == nullptr)
    {
        cout << "No items available.\n";
        return;
    }

    cout << "\nItems in Sorted Order:\n";
    displayInOrder(root);
}