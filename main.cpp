#include <iostream>
#include "RobotNavigation.h"

using namespace std;

int main()
{
    RobotNavigation robot;

    int choice;

    do
    {
        cout << "\n=================================" << endl;
        cout << " ROBOT NAVIGATION MODULE" << endl;
        cout << "=================================" << endl;
        cout << "1. Move Forward" << endl;
        cout << "2. Move Left" << endl;
        cout << "3. Move Right" << endl;
        cout << "4. Display Path" << endl;
        cout << "5. Return To Start" << endl;
        cout << "6. Simulate Obstacle" << endl;
        cout << "0. Exit" << endl;
        cout << "=================================" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            robot.moveForward();
            break;

        case 2:
            robot.moveLeft();
            break;

        case 3:
            robot.moveRight();
            break;

        case 4:
            robot.displayPath();
            break;

        case 5:
            robot.returnToStart();
            break;

        case 6:
            robot.simulateObstacle();
            break;

        case 0:
            cout << "Exiting Program..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}