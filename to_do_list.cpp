
//TO-DO-LIST

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description << " (";
        if (tasks[i].completed) {
            cout << "Completed";
        } else {
            cout << "Pending";
        }
        cout << ")" << endl;
    }
}

void markTaskAsCompleted() {
    int taskIndex;
    cout << "Enter task number to mark as completed: ";
    cin >> taskIndex;
    cin.ignore(); // ignore the newline character

    if (taskIndex < 1 || taskIndex > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks[taskIndex - 1].completed = true;
    cout << "Task marked as completed." << endl;
}

void removeTask() {
    int taskIndex;
    cout << "Enter task number to remove: ";
    cin >> taskIndex;
    cin.ignore(); // ignore the newline character

    if (taskIndex < 1 || taskIndex > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks.erase(tasks.begin() + taskIndex - 1);
    cout << "Task removed successfully." << endl;
}

int main() {
    int choice;

    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // ignore the newline character

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
