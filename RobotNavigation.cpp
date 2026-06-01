#include "RobotNavigation.h"

void RobotNavigation::moveForward()
{
    pathStack.push("FORWARD");

    cout << "Robot moved FORWARD." << endl;
}

void RobotNavigation::moveLeft()
{
    pathStack.push("LEFT");

    cout << "Robot moved LEFT." << endl;
}

void RobotNavigation::moveRight()
{
    pathStack.push("RIGHT");

    cout << "Robot moved RIGHT." << endl;
}

void RobotNavigation::displayPath()
{
    pathStack.display();
}

void RobotNavigation::returnToStart()
{
    if (pathStack.isEmpty())
    {
        cout << "No path recorded." << endl;
        return;
    }

    cout << "\nReturning to Start...\n";

    while (!pathStack.isEmpty())
    {
        cout << "Undo "
            << pathStack.pop()
            << endl;
    }

    cout << "\nRobot returned safely." << endl;
}

void RobotNavigation::simulateObstacle()
{
    if (pathStack.isEmpty())
    {
        cout << "No path available for backtracking." << endl;
        return;
    }

    cout << "\nObstacle detected!" << endl;

    cout << "Backtracking..." << endl;

    cout << "Undo "
        << pathStack.pop()
        << endl;
}