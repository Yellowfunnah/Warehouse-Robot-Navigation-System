#pragma once

#include <string>
using namespace std;

class MovementNode
{
public:
    string direction;
    MovementNode* next;

    MovementNode(string dir)

    {
        direction = dir;
        next = nullptr;
    }
};