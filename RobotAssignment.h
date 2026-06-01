#ifndef ROBOT_ASSIGNMENT_H
#define ROBOT_ASSIGNMENT_H

enum RobotStatus
{
    Available,
    Busy,
    Maintenance
};

struct Robot
{
    int robotId;
    char robotName[30];
    RobotStatus status;
    int assignedTaskCount;
};

struct TaskAssignment
{
    int taskId;
    char taskName[50];
    int robotId;
    char robotName[30];
    bool active;
};

struct CircularRobotQueue
{
    int robotIndexes[20];
    int front;
    int rear;
    int count;
};

class RobotAssignmentModule
{
private:
    static const int MAX_ROBOTS = 20;
    static const int MAX_ASSIGNMENTS = 100;

    Robot robots[MAX_ROBOTS];
    TaskAssignment assignments[MAX_ASSIGNMENTS];
    CircularRobotQueue robotQueue;
    int robotCount;
    int assignmentCount;

    void copyText(char destination[], const char source[], int size);
    void initializeQueue();
    bool enqueueRobot(int robotIndex);
    bool dequeueRobot(int& robotIndex);
    int findRobotPosition(int robotId) const;
    const char* getStatusText(RobotStatus status) const;

public:
    RobotAssignmentModule();

    bool addRobot(int robotId, const char robotName[]);
    bool setRobotStatus(int robotId, RobotStatus status);
    bool assignTask(int taskId, const char taskName[]);
    bool completeTask(int taskId);

    void displayAssignmentList() const;
    void displayCurrentRobotHandlingEachTask() const;
    void displayRobotStatusOverview() const;
};

#endif
