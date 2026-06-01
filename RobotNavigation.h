#pragma once

#include <iostream>
#include <string>
#include "NavigationStack.h"

using namespace std;

class RobotNavigation
{
private:
    NavigationStack pathStack;

public:
    void moveForward();

    void moveLeft();

    void moveRight();

    void displayPath();

    void returnToStart();

    void simulateObstacle();
};