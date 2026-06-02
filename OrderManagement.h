// Made by Dylan Denny TP074870

#ifndef ORDERMANAGEMENT_H
#define ORDERMANAGEMENT_H

#include <iostream>
#include <string>
using namespace std;

// Class, duh
class Order
{
public:
    int orderID;
    string customerName;
    string itemName;

    Order();
};

// Order management class
class OrderManagement
{
private:
    static const int MAX = 100;

    Order queue[MAX];
    Order completed[MAX];

    int front;
    int rear;
    int completedCount;
    int nextOrderID;

public:
	OrderManagement(); // Constructor, foo

	int generateOrderID(); // Lil helper to generate ID

	bool isEmpty(); // Check if the queue is empty, self-explanatory
	bool isFull(); // Check if the queue is full, duh

    void enqueueOrder(Order o);
    void dequeueOrder();
    void peekOrder();

    void displayPendingOrders();
    void displayCompletedOrders();
};

// Menu for main.cpp
void orderManagementMenu();

#endif