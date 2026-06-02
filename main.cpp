#include <iostream>
#include "RobotNavigation.h"
#include "OrderManagement.h"

using namespace std;

// Function Prototype
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
            cout << "\nRobot Assignment Module Not Implemented Yet." << endl;
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
