// Made by Dylan Denny TP074870

#include "OrderManagement.h"

// Constructors, foo
Order::Order()
{
    orderID = 0;
    customerName = "";
    itemName = "";
}

OrderManagement::OrderManagement()
{
    front = -1;
    rear = -1;
    completedCount = 0;
    nextOrderID = 1;
}

// Generate ID
int OrderManagement::generateOrderID()
{
    return nextOrderID++;
}

// Check if the queue is empty, self-explanatory
bool OrderManagement::isEmpty()
{
    return front == -1 || front > rear;
}

// Check if the queue is full, duh
bool OrderManagement::isFull()
{
    return rear == MAX - 1;
}

// Enqueue (add order)
void OrderManagement::enqueueOrder(Order o)
{
    if (isFull())
    {
        cout << "Queue Overflow! System overloaded.\n";
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = o;

    cout << "Order added successfully!\n";
}

// Dequeue (process order)
void OrderManagement::dequeueOrder()
{
    if (isEmpty())
    {
        cout << "No orders to process.\n";
        return;
    }

    Order current = queue[front];

    cout << "\nProcessing Order:\n";
    cout << "ID: " << current.orderID << endl;
    cout << "Customer: " << current.customerName << endl;
    cout << "Item: " << current.itemName << endl;

    completed[completedCount++] = current;

    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

// Peek, view the front order without removing it
void OrderManagement::peekOrder()
{
    if (isEmpty())
    {
        cout << "No current order.\n";
        return;
    }

    Order o = queue[front];

    cout << "\nNext Order:\n";
    cout << "ID: " << o.orderID << endl;
    cout << "Customer: " << o.customerName << endl;
    cout << "Item: " << o.itemName << endl;
}

// Display the queue of pending orders.
void OrderManagement::displayPendingOrders()
{
    if (isEmpty())
    {
        cout << "No pending orders.\n";
        return;
    }

    cout << "\nPending Orders:\n";

    for (int i = front; i <= rear; i++)
    {
        cout << i - front + 1 << ". "
            << queue[i].orderID << " | "
            << queue[i].customerName << " | "
            << queue[i].itemName << endl;
    }
}

// Don't be fooled gangalang, this display the completed orders.
void OrderManagement::displayCompletedOrders()
{
    if (completedCount == 0)
    {
        cout << "No completed orders.\n";
        return;
    }

    cout << "\nCompleted Orders:\n";

    for (int i = 0; i < completedCount; i++)
    {
        cout << i + 1 << ". "
            << completed[i].orderID << " | "
            << completed[i].customerName << " | "
            << completed[i].itemName << endl;
    }
}

void orderManagementMenu()
{
    OrderManagement om;
    int choice;
    while (true)
    {
        cout << "\n=================================\n";
        cout << " ORDER MANAGEMENT MODULE\n";
        cout << "=================================\n";
        cout << "1. Add New Order\n";
        cout << "2. Process Order\n";
        cout << "3. View Next Order\n";
        cout << "4. Display Pending Orders\n";
        cout << "5. Display Completed Orders\n";
        cout << "0. Back\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cout << "Invalid choice! Enter number only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 0)
            break;

        switch (choice) {
        case 1:
        {
            Order o;

            o.orderID = om.generateOrderID();
            cin.ignore();

            cout << "Enter Customer Name: ";
            getline(cin, o.customerName);

            cout << "Enter Item Name: ";
            getline(cin, o.itemName);

            om.enqueueOrder(o); 
            break;
        }

        case 2:
            om.dequeueOrder();
            break;

        case 3:
            om.peekOrder();
            break;

        case 4:
            om.displayPendingOrders();
            break;

        case 5:
            om.displayCompletedOrders();
            break;

        default:
            cout << "Invalid option!\n";
        }
    }
}