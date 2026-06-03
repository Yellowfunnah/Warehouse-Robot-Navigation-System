#include <iostream>
#include "RobotNavigation.h"
#include "OrderManagement.h"
#include "RobotAssignment.h"
#include "ItemManagement.h"
#include "WarehouseLayout.h"

using namespace std;

// Function Prototype
void robotAssignmentMenu();
void robotNavigationMenu();
void itemManagementMenu();
void warehouseLayoutMenu();

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
            itemManagementMenu();
            break;

        case 5:
            warehouseLayoutMenu();
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

void robotNavigationMenu()
{
    static RobotNavigation robot;

    int choice;
    int movementChoice;

    do
    {
        cout << "\n=================================" << endl;
        cout << " ROBOT NAVIGATION MODULE" << endl;
        cout << "=================================" << endl;
        cout << "1. Start Navigation" << endl;
        cout << "2. Display Current Path" << endl;
        cout << "3. Return To Start" << endl;
        cout << "4. View Navigation Log" << endl;
        cout << "5. View Latest Movement" << endl;
        cout << "6. View Total Movements" << endl;
        cout << "0. Back To Main Menu" << endl;
        cout << "=================================" << endl;
        cout << "Enter Choice: ";

        while (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number: ";

            cin.clear();
            cin.ignore(1000, '\n');
        }
        switch (choice)
        {
        case 1:

            do
            {
                cout << "\n=================================" << endl;
                cout << " MOVEMENT CONTROL" << endl;
                cout << "=================================" << endl;
                cout << "1. Move Forward" << endl;
                cout << "2. Move Left" << endl;
                cout << "3. Move Right" << endl;
                cout << "4. Obstacle Detected" << endl;
                cout << "0. Finish Navigation" << endl;
                cout << "=================================" << endl;
                cout << "Enter Choice: ";

                while (!(cin >> movementChoice))
                {
                    cout << "Invalid input! Please enter a number: ";

                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                switch (movementChoice)
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
                    robot.simulateObstacle();
                    break;

                case 0:
                    cout << "\nNavigation Session Completed." << endl;
                    break;

                default:
                    cout << "\nInvalid Choice!" << endl;
                }

            } while (movementChoice != 0);

            break;

        case 2:
            robot.displayPath();
            break;

        case 3:
            robot.returnToStart();
            break;

        case 4:
            robot.viewNavigationLog();
            break;

        case 5:
            robot.viewLatestMovement();
            break;

        case 6:
            robot.viewMovementCount();
            break;

        case 0:
            cout << "\nReturning to Main Menu..." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while (choice != 0);
}

void itemManagementMenu()
{
    ItemManagement itemManager;

    itemManager.insertItem("I001", "Mouse", "Zone A Shelf 5");
    itemManager.insertItem("I002", "Monitor", "Zone B Shelf 2");
    itemManager.insertItem("I003", "Keyboard", "Zone C Shelf 1");

    int choice;

    do
    {
        cout << "\n=================================" << endl;
        cout << " ITEM SEARCH & MANAGEMENT MODULE" << endl;
        cout << "=================================" << endl;
        cout << "1. Insert Item" << endl;
        cout << "2. Search Item" << endl;
        cout << "3. Update Item" << endl;
        cout << "4. Delete Item" << endl;
        cout << "5. Display All Items" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "=================================" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string id, name, location;

            cout << "Enter Item ID: ";
            cin >> id;

            // Check duplicate first
            if (itemManager.idExists(id))
            {
                cout << "Item ID already exists. Insertion failed.\n";
                break;
            }

            cin.ignore();

            cout << "Enter Item Name: ";
            getline(cin, name);

            cout << "Enter Item Location: ";
            getline(cin, location);

            itemManager.insertItem(id, name, location);
            break;
        }

        case 2:
        {
            string id;

            cout << "Enter Item ID to search: ";
            cin >> id;

            itemManager.searchItem(id);
            break;
        }

        case 3:
        {
            string id, newName, newLocation;

            cout << "Enter Item ID to update: ";
            cin >> id;

            cin.ignore();

            cout << "Enter New Item Name: ";
            getline(cin, newName);

            cout << "Enter New Location: ";
            getline(cin, newLocation);

            itemManager.updateItem(id, newName, newLocation);
            break;
        }

        case 4:
        {
            string id;

            cout << "Enter Item ID to delete: ";
            cin >> id;

            itemManager.deleteItem(id);
            break;
        }

        case 5:
            itemManager.displayItems();
            break;

        case 0:
            cout << "\nReturning to Main Menu..." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while (choice != 0);
}

void warehouseLayoutMenu()
{
    WarehouseLayout warehouse;
    warehouse.buildSampleLayout(); // load the preset layout on entry

    int choice;

    do
    {
        cout << "\n=================================" << endl;
        cout << " WAREHOUSE LAYOUT MODULE" << endl;
        cout << "=================================" << endl;
        cout << "1. Display Warehouse Layout" << endl;
        cout << "2. Add Zone" << endl;
        cout << "3. Add Aisle" << endl;
        cout << "4. Add Shelf" << endl;
        cout << "5. Search Location" << endl;
        cout << "6. Show Path to Location" << endl;
        cout << "7. Traverse Entire Warehouse" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "=================================" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            warehouse.displayLayout();
            break;

        case 2:
            warehouse.addZone();
            break;

        case 3:
            warehouse.addAisle();
            break;

        case 4:
            warehouse.addShelf();
            break;

        case 5:
            warehouse.searchLocation();
            break;

        case 6:
            warehouse.showPathToLocation();
            break;

        case 7:
            warehouse.traverseWarehouse();
            break;

        case 0:
            cout << "\nReturning to Main Menu..." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while (choice != 0);
}

void robotAssignmentMenu()
{
    cout << "\nRobot Assignment Module Not Implemented Yet." << endl;
}