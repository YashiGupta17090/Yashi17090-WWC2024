//Q4: Design a system in C++ that uses a linked list to simulate a real-time task scheduler for a multi-threaded operating
//system. Each node in the linked list represents a task, containing attributes like a unique task ID, task priority,
//estimated execution time, and a pointer to the next task. The linked list must dynamically adapt to new tasks being added,
//tasks completing, or tasks being pre-empted based on their priority. Implement functionality to insert tasks into the list
//in priority order (higher priority tasks come first), remove tasks upon completion, and dynamically reallocate execution slots
//if a higher priority task is added mid-execution. Additionally, the system should support a circular linked list to handle periodic tasks
//that need to re-enter the scheduling queue after a defined time interval. The implementation must ensure efficient memory usage and handle edge cases,
//such as managing tasks with the same priority, handling an empty task queue, and dealing with corrupted nodes. The program should output 
//the current state of the task list, showing the order of execution and periodically updating it as tasks are added, completed, or preempted in real-time.
//This problem challenges your understanding of advanced linked list manipulation, dynamic memory management, and multi-threaded
//system simulation.
#include <iostream>
#include <memory>
using namespace std;

struct Task {
    int taskID;
    int priority;
    int executionTime;
    shared_ptr<Task> next;
    Task(int id, int pr, int execTime) : taskID(id), priority(pr), executionTime(execTime), next(nullptr) {}
};

class TaskScheduler {
    shared_ptr<Task> head;

public:
    TaskScheduler() : head(nullptr) {}

    // Insert task in priority order (higher priority first)
    void insertTask(int taskID, int priority, int executionTime) {
        shared_ptr<Task> newTask = make_shared<Task>(taskID, priority, executionTime);
        
        if (!head || head->priority < priority) {
            newTask->next = head;
            head = newTask;
        } else {
            shared_ptr<Task> temp = head;
            while (temp->next && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newTask->next = temp->next;
            temp->next = newTask;
        }
    }

    // Remove task after completion
    void removeTask(int taskID) {
        if (!head) return;
        if (head->taskID == taskID) {
            head = head->next;
            return;
        }
        shared_ptr<Task> temp = head;
        while (temp->next && temp->next->taskID != taskID) {
            temp = temp->next;
        }
        if (temp->next) {
            temp->next = temp->next->next;
        }
    }

    // Simulate task execution and periodic task handling
    void executeTasks() {
        shared_ptr<Task> temp = head;
        while (temp) {
            cout << "Executing Task ID: " << temp->taskID << ", Priority: " << temp->priority << ", Time: " << temp->executionTime << endl;
            removeTask(temp->taskID);
            temp = temp->next;
        }
    }

    // Display current state of tasks
    void displayTasks() {
        shared_ptr<Task> temp = head;
        while (temp) {
            cout << "Task ID: " << temp->taskID << ", Priority: " << temp->priority << ", Execution Time: " << temp->executionTime << endl;
            temp = temp->next;
        }
    }
};

int main() {
    TaskScheduler scheduler;

    // Insert tasks
    scheduler.insertTask(1, 3, 10); // Task 1, Priority 3
    scheduler.insertTask(2, 1, 5);  // Task 2, Priority 1
    scheduler.insertTask(3, 2, 7);  // Task 3, Priority 2

    cout << "Current Tasks:" << endl;
    scheduler.displayTasks();

    // Execute tasks
    cout << "\nExecuting Tasks..." << endl;
    scheduler.executeTasks();

    return 0;
}

