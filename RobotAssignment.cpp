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

bool RobotAssignmentModule::enqueueRobot(int robotIndex)
{
    if (robotQueue.count == MAX_ROBOTS)
    {
        return false;
    }

    robotQueue.rear = (robotQueue.rear + 1) % MAX_ROBOTS;
    robotQueue.robotIndexes[robotQueue.rear] = robotIndex;
    robotQueue.count++;
    return true;
}

bool RobotAssignmentModule::dequeueRobot(int& robotIndex)
{
    if (robotQueue.count == 0)
    {
        return false;
    }

    robotIndex = robotQueue.robotIndexes[robotQueue.front];
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
    int robotIndex = findRobotPosition(robotId);

    if (robotIndex == -1)
    {
        return false;
    }

    robots[robotIndex].status = status;
    return true;
}

bool RobotAssignmentModule::assignTask(int taskId, const char taskName[])
{
    if (robotQueue.count == 0 || assignmentCount == MAX_ASSIGNMENTS)
    {
        return false;
    }

    int checkedRobots = robotQueue.count;

    // Check each robot once, rotating the queue as we go.
    for (int i = 0; i < checkedRobots; i++)
    {
        int robotIndex;
        dequeueRobot(robotIndex);
        enqueueRobot(robotIndex);

        if (robots[robotIndex].status == Available)
        {
            assignments[assignmentCount].taskId = taskId;
            copyText(assignments[assignmentCount].taskName, taskName, 50);
            assignments[assignmentCount].robotId = robots[robotIndex].robotId;
            copyText(assignments[assignmentCount].robotName, robots[robotIndex].robotName, 30);
            assignments[assignmentCount].active = true;

            robots[robotIndex].status = Busy;
            robots[robotIndex].assignedTaskCount++;
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
        if (assignments[i].taskId == taskId && assignments[i].active)
        {
            int robotIndex = findRobotPosition(assignments[i].robotId);
            assignments[i].active = false;

            if (robotIndex != -1 && robots[robotIndex].status == Busy)
            {
                robots[robotIndex].status = Available;
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

    if (robotCount == 0)
    {
        cout << "No robots added.\n";
        return;
    }

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
        if (assignments[i].active)
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
