#pragma once

#include <iostream>
#include <string>

using namespace std;

struct MovementNode
{
    string direction;
    MovementNode* next;
};

class NavigationStack
{
private:
    MovementNode* top;

public:
    NavigationStack();

    ~NavigationStack();

    void push(string direction);

    string pop();

    bool isEmpty();

    string peek();

    void display();
};