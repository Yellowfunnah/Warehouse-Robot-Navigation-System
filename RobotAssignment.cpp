#include "RobotAssignment.h"
#include <iostream>

using namespace std;

RobotAssignmentModule::RobotAssignmentModule()
{
    robotCount = 0;
    assignmentCount = 0;
    initializeQueue();
}

void RobotAssignmentModule::copyText(char destination[], const char source[], int size)
{
    int index = 0;

    if (source != nullptr)
    {
        while (index < size - 1 && source[index] != '\0')
        {
            destination[index] = source[index];
            index++;
        }
    }

    destination[index] = '\0';
}

void RobotAssignmentModule::initializeQueue()
{
    robotQueue.front = 0;
    robotQueue.rear = -1;
    robotQueue.count = 0;
}

bool RobotAssignmentModule::enqueueRobot(int robotPosition)
{
    if (robotQueue.count == MAX_ROBOTS)
    {
        return false;
    }

    robotQueue.rear = (robotQueue.rear + 1) % MAX_ROBOTS;
    robotQueue.robotPositions[robotQueue.rear] = robotPosition;
    robotQueue.count++;
    return true;
}

bool RobotAssignmentModule::dequeueRobot(int& robotPosition)
{
    if (robotQueue.count == 0)
    {
        return false;
    }

    robotPosition = robotQueue.robotPositions[robotQueue.front];
    robotQueue.front = (robotQueue.front + 1) % MAX_ROBOTS;
    robotQueue.count--;
    return true;
}

int RobotAssignmentModule::findRobotPosition(int robotId) const
{
    for (int i = 0; i < robotCount; i++)
    {
        if (robots[i].robotId == robotId)
        {
            return i;
        }
    }

    return -1;
}

const char* RobotAssignmentModule::getStatusText(RobotStatus status) const
{
    if (status == Available)
    {
        return "Available";
    }

    if (status == Busy)
    {
        return "Busy";
    }

    return "Maintenance";
}

bool RobotAssignmentModule::addRobot(int robotId, const char robotName[])
{
    if (robotCount == MAX_ROBOTS || findRobotPosition(robotId) != -1)
    {
        return false;
    }

    robots[robotCount].robotId = robotId;
    copyText(robots[robotCount].robotName, robotName, 30);
    robots[robotCount].status = Available;
    robots[robotCount].assignedTaskCount = 0;

    enqueueRobot(robotCount);
    robotCount++;
    return true;
}

bool RobotAssignmentModule::setRobotStatus(int robotId, RobotStatus status)
{
    int robotPosition = findRobotPosition(robotId);

    if (robotPosition == -1)
    {
        return false;
    }

    robots[robotPosition].status = status;
    return true;
}

bool RobotAssignmentModule::assignTask(int taskId, const char taskName[])
{
    if (robotQueue.count == 0 || assignmentCount == MAX_ASSIGNMENTS)
    {
        return false;
    }

    int robotsChecked = robotQueue.count;

    // Check each robot once while keeping the queue rotating.
    for (int i = 0; i < robotsChecked; i++)
    {
        int robotPosition;
        dequeueRobot(robotPosition);
        enqueueRobot(robotPosition);

        if (robots[robotPosition].status == Available)
        {
            assignments[assignmentCount].taskId = taskId;
            copyText(assignments[assignmentCount].taskName, taskName, 50);
            assignments[assignmentCount].robotId = robots[robotPosition].robotId;
            copyText(assignments[assignmentCount].robotName, robots[robotPosition].robotName, 30);
            assignments[assignmentCount].isActive = true;

            robots[robotPosition].status = Busy;
            robots[robotPosition].assignedTaskCount++;
            assignmentCount++;
            return true;
        }
    }

    return false;
}

bool RobotAssignmentModule::completeTask(int taskId)
{
    for (int i = 0; i < assignmentCount; i++)
    {
        if (assignments[i].taskId == taskId && assignments[i].isActive)
        {
            int robotPosition = findRobotPosition(assignments[i].robotId);
            assignments[i].isActive = false;

            if (robotPosition != -1 && robots[robotPosition].status == Busy)
            {
                robots[robotPosition].status = Available;
            }

            return true;
        }
    }

    return false;
}

void RobotAssignmentModule::displayAssignmentList() const
{
    cout << "\nRobot Assignment List\n";
    cout << "---------------------\n";

    if (assignmentCount == 0)
    {
        cout << "No task assignments recorded.\n";
        return;
    }

    cout << "Task ID | Task Name | Robot ID | Robot Name | Status\n";

    for (int i = 0; i < assignmentCount; i++)
    {
        cout << assignments[i].taskId << " | "
            << assignments[i].taskName << " | "
            << assignments[i].robotId << " | "
            << assignments[i].robotName << " | ";

        if (assignments[i].isActive)
        {
            cout << "Active\n";
        }
        else
        {
            cout << "Completed\n";
        }
    }

    cout << "\nRobot Workload Summary\n";

    for (int i = 0; i < robotCount; i++)
    {
        cout << robots[i].robotId << " - " << robots[i].robotName
            << " | Total assigned: " << robots[i].assignedTaskCount << "\n";
    }
}

void RobotAssignmentModule::displayCurrentRobotHandlingEachTask() const
{
    cout << "\nCurrent Robot Handling Each Task\n";
    cout << "--------------------------------\n";

    bool hasActiveTask = false;

    for (int i = 0; i < assignmentCount; i++)
    {
        if (assignments[i].isActive)
        {
            cout << "Task " << assignments[i].taskId << " (" << assignments[i].taskName
                << ") -> Robot " << assignments[i].robotId << " - "
                << assignments[i].robotName << "\n";
            hasActiveTask = true;
        }
    }

    if (!hasActiveTask)
    {
        cout << "No active task assignments.\n";
    }
}

void RobotAssignmentModule::displayRobotStatusOverview() const
{
    cout << "\nRobot Status Overview\n";
    cout << "---------------------\n";

    if (robotCount == 0)
    {
        cout << "No robots added.\n";
        return;
    }

    for (int i = 0; i < robotCount; i++)
    {
        cout << robots[i].robotId << " - " << robots[i].robotName
            << " | Status: " << getStatusText(robots[i].status) << "\n";
    }
}
