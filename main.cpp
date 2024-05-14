#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    virtual void display() const = 0;
    virtual bool isCompleted() const = 0;
    virtual void markAsCompleted() = 0;
};

enum class Priority {
    Low,
    Medium,
    High
};

class TaskItem : public Task {
private:
    string title;
    string description;
    bool completed;
    Priority priority;

public:
    TaskItem(string title_, string description_, Priority priority_) : title(title_), description(description_), completed(false), priority(priority_) {}

    void display() const override {
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Completed: " << (completed ? "Yes" : "No") << endl;
    }

    bool isCompleted() const override {
        return completed;
    }

    void markAsCompleted() override {
        completed = true;
    }

    Priority getPriority() const {
        return priority;
    }
};

class Note {
public:
    string text;
};

class TaskList {
private:
    vector<TaskItem> tasks;
    vector<Note> notes;

public:
    void addTask(const TaskItem& task) {
        tasks.push_back(task);
    }

    void addNote(const Note& note) {
        notes.push_back(note);
    }

    void displayAll() {
        for (const auto& task : tasks) {
            task.display();
        }
    }

    TaskItem* getTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            return &tasks[index];
        } else {
            return nullptr;
        }
    }

    Note* getNote(int index) {
        if (index >= 0 && index < notes.size()) {
            return &notes[index];
        } else {
            return nullptr;
        }
    }

    int getTotalTasks() const {
        return tasks.size();
    }

    friend bool compareByPriority(const TaskItem& task1, const TaskItem& task2);
};

bool compareByPriority(const TaskItem& task1, const TaskItem& task2) {
    return static_cast<int>(task1.getPriority()) > static_cast<int>(task2.getPriority());
}
int main() {
    TaskList taskList;
    int choice;

    while (true) {
        cout << "1. Add Task\";
        cout << "2. Add Note\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Display All Tasks and Notes\n";
        cout << "5. Compare Tasks by Priority\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, description;
                int priority;
                cout << "Enter task title: ";
                cin >> title;
                cout << "Enter task description: ";
                cin >> description;
                cout << "Enter task priority (0 for Low, 1 for Medium, 2 for High): ";
                cin >> priority;
                taskList.addTask(TaskItem(title, description, static_cast<Priority>(priority)));
                break;
            }
            case 2: {
                string text;
                cout << "Enter note text: ";
                cin >> text;
                Note note;
                note.text = text;
                taskList.addNote(note);
                break;
            }
            case 3: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                TaskItem* task = taskList.getTask(index);
                if (task != nullptr) {
                    task->markAsCompleted();
                } else {
                    cout << "Invalid task index.\n";
                }
                break;
            }
            case 4: {
                taskList.displayAll();
                break;
            }
            case 5: {
                int index1, index2;
                cout << "Enter first task index for comparison: ";
                cin >> index1;
                cout << "Enter second task index for comparison: ";
                cin >> index2;
                TaskItem* task1 = taskList.getTask(index1);
                TaskItem* task2 = taskList.getTask(index2);
                if (task1 != nullptr && task2 != nullptr) {
                    if (compareByPriority(*task1, *task2)) {
                        cout << "First task has higher priority.\n";
                    } else {
                        cout << "Second task has higher priority.\n";
                    }
                } else {
                    cout << "Invalid task index.\n";
                }
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    return 0;
}
