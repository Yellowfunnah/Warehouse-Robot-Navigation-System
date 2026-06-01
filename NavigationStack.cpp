#include "NavigationStack.h"

NavigationStack::NavigationStack()
{
    top = nullptr;
}

bool NavigationStack::isEmpty()
{
    return top == nullptr;
}

void NavigationStack::push(string move)
{
    MovementNode* newNode = new MovementNode(move);

    newNode->next = top;

    top = newNode;
}

string NavigationStack::pop()
{
    if (isEmpty())
    {
        return "";
    }

    MovementNode* temp = top;

    string move = temp->direction;

    top = top->next;

    delete temp;

    return move;
}

string NavigationStack::peek()
{
    if (isEmpty())
    {
        return "";
    }

    return top->direction;
}

void NavigationStack::display()
{
    if (isEmpty())
    {
        cout << "No path recorded." << endl;
        return;
    }

    MovementNode* current = top;

    cout << "\nCurrent Path:\n";

    while (current != nullptr)
    {
        cout << current->direction << endl;
        current = current->next;
    }
}