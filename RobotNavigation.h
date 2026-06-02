#pragma once

#include <iostream>
#include <string>
#include "NavigationStack.h"

using namespace std;

class RobotNavigation
{
private:
    NavigationStack pathStack;

    string navigationLog[100];
    int logCount;

    int movementCount;

public:
    RobotNavigation();

    void moveForward();

    void moveLeft();

    void moveRight();

    void displayPath();

    void returnToStart();

    void simulateObstacle();

    void viewNavigationLog();

    void viewLatestMovement();

    void viewMovementCount();
};

// Menu Function
void robotNavigationMenu();