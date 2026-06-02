#include <iostream>
#include "RobotNavigation.h"
#include "OrderManagement.h"
#include "RobotAssignment.h"

using namespace std;

// Function Prototype
void robotAssignmentMenu();
void robotNavigationMenu();

int main()
{
    int choice;

    do
    {
        cout << "\n=========================================" << endl;
        cout << " WAREHOUSE ROBOT NAVIGATION SYSTEM" << endl;
        cout << "=========================================" << endl;
        cout << "1. Order Management" << endl;
        cout << "2. Robot Assignment" << endl;
        cout << "3. Robot Navigation" << endl;
        cout << "4. Item Management" << endl;
        cout << "5. Warehouse Layout" << endl;
        cout << "0. Exit" << endl;
        cout << "=========================================" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            orderManagementMenu();
            break;

        case 2:
            robotAssignmentMenu();
            break;

        case 3:
            robotNavigationMenu();
            break;

        case 4:
            cout << "\nItem Management Module Not Implemented Yet." << endl;
            break;

        case 5:
            cout << "\nWarehouse Layout Module Not Implemented Yet." << endl;
            break;

        case 0:
            cout << "\nExiting System..." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}

void robotAssignmentMenu()
{
    RobotAssignmentModule robotAssignment;
    int choice;

    do
    {
        cout << "\n=================================" << endl;
        cout << " ROBOT ASSIGNMENT MODULE" << endl;
        cout << "=================================" << endl;
        cout << "1. Add Robot" << endl;
        cout << "2. Assign Task" << endl;
        cout << "3. Complete Task" << endl;
        cout << "4. Set Robot Status" << endl;
        cout << "5. Display Assignment History" << endl;
        cout << "6. Display Current Task Handlers" << endl;
        cout << "7. Display Robot Status Overview" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "=================================" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int robotId;
            char robotName[30];

            cout << "Enter Robot ID: ";
            cin >> robotId;
            cout << "Enter Robot Name: ";
            cin >> robotName;

            if (robotAssignment.addRobot(robotId, robotName))
            {
                cout << "Robot added successfully." << endl;
            }
            else
            {
                cout << "Robot could not be added." << endl;
            }
            break;
        }

        case 2:
        {
            int taskId;
            char taskName[50];

            cout << "Enter Task ID: ";
            cin >> taskId;
            cout << "Enter Task Name: ";
            cin >> taskName;

            if (robotAssignment.assignTask(taskId, taskName))
            {
                cout << "Task assigned successfully." << endl;
            }
            else
            {
                cout << "No available robot for this task." << endl;
            }
            break;
        }

        case 3:
        {
            int taskId;

            cout << "Enter Task ID to complete: ";
            cin >> taskId;

            if (robotAssignment.completeTask(taskId))
            {
                cout << "Task completed successfully." << endl;
            }
            else
            {
                cout << "Task not found or already completed." << endl;
            }
            break;
        }

        case 4:
        {
            int robotId;
            int statusChoice;

            cout << "Enter Robot ID: ";
            cin >> robotId;
            cout << "1. Available" << endl;
            cout << "2. Busy" << endl;
            cout << "3. Maintenance" << endl;
            cout << "Choose Status: ";
            cin >> statusChoice;

            RobotStatus status = Available;

            if (statusChoice == 2)
            {
                status = Busy;
            }
            else if (statusChoice == 3)
            {
                status = Maintenance;
            }

            if (robotAssignment.setRobotStatus(robotId, status))
            {
                cout << "Robot status updated." << endl;
            }
            else
            {
                cout << "Robot not found." << endl;
            }
            break;
        }

        case 5:
            robotAssignment.displayAssignmentList();
            break;

        case 6:
            robotAssignment.displayCurrentRobotHandlingEachTask();
            break;

        case 7:
            robotAssignment.displayRobotStatusOverview();
            break;

        case 0:
            cout << "\nReturning to Main Menu..." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while (choice != 0);
}

void robotNavigationMenu()
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
        cout << "0. Back to Main Menu" << endl;
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
            cout << "\nReturning to Main Menu..." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while (choice != 0);
}
