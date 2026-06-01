#pragma once

#include <iostream>
#include <string>
#include "MovementNode.h"

using namespace std;

class NavigationStack
{
private:
    MovementNode* top;

public:
    NavigationStack();

    void push(string move);

    string pop();

    string peek();

    bool isEmpty();

    void display();
};