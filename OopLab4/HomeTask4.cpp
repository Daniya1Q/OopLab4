#include <iostream>
#include <list>
#include <string>

using namespace std;

class ToDoList {
private:
    struct Item {
        string task;
        list<Item> subtasks; 
    };

    list<Item> items; 

public:
    // Add Task Method
    void addTask(const string& task) {
        Item newItem;
        newItem.task = task;
        items.push_back(newItem);
    }

    // Add SubTask Method
    void addSubtask(int taskIndex, const string& subtask) {
        auto it = items.begin();
        advance(it, taskIndex);
        it->subtasks.push_back({ subtask, {} });
    }

    // Display Method
    void display() {
        displayItems(items, 0);
    }

    // Delete Completed Tasks Method
    void deleteCompletedTasks() {
        deleteCompletedTasksHelper(items);
    }

private:
    // Display Items in List
    void displayItems(const list<Item>& itemList, int level) {
        for (const auto& item : itemList) {
            for (int i = 0; i < level; ++i) cout << "  "; 
            cout << "- " << item.task << endl;
            displayItems(item.subtasks, level + 1); 
        }
    }

    // Delete Completed Tasks
    void deleteCompletedTasksHelper(list<Item>& itemList) {
        auto it = itemList.begin();
        while (it != itemList.end()) {
            if (isTaskCompleted(*it)) {
                it = itemList.erase(it); 
            }
            else {
                deleteCompletedTasksHelper(it->subtasks); 
                ++it;
            }
        }
    }

    
    bool isTaskCompleted(const Item& item) {
        return item.subtasks.empty();
    }
};

int main() {
    ToDoList toDo;
    int choice;

    do {
        cout << "\nMenu:\n1. Add Task\n2. Add Subtask\n3. Delete Completed Tasks\n4. Display To-Do List\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string task;
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, task);
            toDo.addTask(task);
            break;
        }
        case 2: {
            int taskIndex;
            string subtask;
            cout << "Enter task index to add subtask: ";
            cin >> taskIndex;
            cout << "Enter subtask: ";
            cin.ignore();
            getline(cin, subtask);
            toDo.addSubtask(taskIndex - 1, subtask); 
            break;
        }
        case 3:
            toDo.deleteCompletedTasks();
            cout << "Completed tasks deleted." << endl;
            break;
        case 4:
            cout << "\nTo-Do List:" << endl;
            toDo.display();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
