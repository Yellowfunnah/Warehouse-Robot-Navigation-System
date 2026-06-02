#include "RobotNavigation.h"

RobotNavigation::RobotNavigation()
{
    logCount = 0;
    movementCount = 0;
}

void RobotNavigation::moveForward()
{
    pathStack.push("FORWARD");

    navigationLog[logCount] = "FORWARD";
    logCount++;

    movementCount++;

    cout << "Robot moved FORWARD." << endl;
}

void RobotNavigation::moveLeft()
{
    pathStack.push("LEFT");

    navigationLog[logCount] = "LEFT";
    logCount++;

    movementCount++;

    cout << "Robot moved LEFT." << endl;
}

void RobotNavigation::moveRight()
{
    pathStack.push("RIGHT");

    navigationLog[logCount] = "RIGHT";
    logCount++;

    movementCount++;

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

void RobotNavigation::viewNavigationLog()
{
    if (logCount == 0)
    {
        cout << "No navigation history recorded." << endl;
        return;
    }

    cout << "\n===== NAVIGATION LOG =====" << endl;

    for (int i = 0; i < logCount; i++)
    {
        cout << i + 1 << ". "
            << navigationLog[i]
            << endl;
    }
}

void RobotNavigation::viewLatestMovement()
{
    if (pathStack.isEmpty())
    {
        cout << "No active path available." << endl;
        return;
    }

    cout << "Latest Movement: "
        << pathStack.peek()
        << endl;
}

void RobotNavigation::viewMovementCount()
{
    cout << "\nTotal Movements Recorded: "
        << movementCount
        << endl;
}

//void robotNavigationMenu()
//{
//    static RobotNavigation robot;
//
//    int choice;
//    int movementChoice;
//
//    do
//    {
//        cout << "\n=================================" << endl;
//        cout << " ROBOT NAVIGATION MODULE" << endl;
//        cout << "=================================" << endl;
//        cout << "1. Start Navigation" << endl;
//        cout << "2. Display Current Path" << endl;
//        cout << "3. Return To Start" << endl;
//        cout << "4. View Navigation Log" << endl;
//        cout << "5. View Latest Movement" << endl;
//        cout << "6. View Total Movements" << endl;
//        cout << "0. Back To Main Menu" << endl;
//        cout << "=================================" << endl;
//        cout << "Enter Choice: ";
//
//        while (!(cin >> choice))
//        {
//            cout << "Invalid input! Please enter a number: ";
//
//            cin.clear();
//            cin.ignore(1000, '\n');
//        }
//        switch (choice)
//        {
//        case 1:
//
//            do
//            {
//                cout << "\n=================================" << endl;
//                cout << " MOVEMENT CONTROL" << endl;
//                cout << "=================================" << endl;
//                cout << "1. Move Forward" << endl;
//                cout << "2. Move Left" << endl;
//                cout << "3. Move Right" << endl;
//                cout << "4. Obstacle Detected" << endl;
//                cout << "0. Finish Navigation" << endl;
//                cout << "=================================" << endl;
//                cout << "Enter Choice: ";
//
//                while (!(cin >> movementChoice))
//                {
//                    cout << "Invalid input! Please enter a number: ";
//
//                    cin.clear();
//                    cin.ignore(1000, '\n');
//                }
//
//                switch (movementChoice)
//                {
//                case 1:
//                    robot.moveForward();
//                    break;
//
//                case 2:
//                    robot.moveLeft();
//                    break;
//
//                case 3:
//                    robot.moveRight();
//                    break;
//
//                case 4:
//                    robot.simulateObstacle();
//                    break;
//
//                case 0:
//                    cout << "\nNavigation Session Completed." << endl;
//                    break;
//
//                default:
//                    cout << "\nInvalid Choice!" << endl;
//                }
//
//            } while (movementChoice != 0);
//
//            break;
//
//        case 2:
//            robot.displayPath();
//            break;
//
//        case 3:
//            robot.returnToStart();
//            break;
//
//        case 4:
//            robot.viewNavigationLog();
//            break;
//
//        case 5:
//            robot.viewLatestMovement();
//            break;
//
//        case 6:
//            robot.viewMovementCount();
//            break;
//
//        case 0:
//            cout << "\nReturning to Main Menu..." << endl;
//            break;
//
//        default:
//            cout << "\nInvalid Choice!" << endl;
//        }
//
//    } while (choice != 0);
//}