#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*Создайте абстрактный класс "Task" с следующими чисто виртуальными методами:

virtual void display() - для отображения информации о задаче.
virtual bool isCompleted() - для проверки выполнена ли задача.
virtual void markAsCompleted() - для отметки задачи как выполненной.*/
class Task {
public:
    // Чисто виртуальный метод для отображения информации о задаче
    virtual void display() = 0;

    // Чисто виртуальный метод для проверки, выполнена ли задача
    virtual bool isCompleted() = 0;

    // Чисто виртуальный метод для отметки задачи как выполненной
    virtual void markAsCompleted() = 0;
};
/*Создайте класс "TaskItem", который наследует абстрактный класс "Task" и содержит следующие поля:

string title - заголовок задачи.
string description - описание задачи.
bool completed - флаг, который указывает, выполнена ли задача.
Класс "TaskItem" должен иметь конструктор, который принимает заголовок и описание задачи, 
а также методы для отображения информации о задаче и отметки задачи как выполненной.*/
class TaskItem : public Task {
private:
    string title;       // Заголовок задачи
    string description; // Описание задачи
    bool completed;    // Флаг, указывающий, выполнена ли задача

public:
    // Конструктор, который принимает заголовок и описание задачи
    TaskItem(string title_, string description_) {
        title = title_;
        description = description_;
        completed = false;
    }

   // Метод для отображения информации о задаче
    void display() override {
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Completed: ";
        if (completed) {
        cout << "Yes"<< endl; } else {
        cout << "No"<< endl; }
    }

    // Метод для проверки, выполнена ли задача
    bool isCompleted() override {
        return completed;
    }

    // Метод для отметки задачи как выполненной
    void markAsCompleted() override {
        completed = true;
    }

};
/*Создайте класс "TaskList" для хранения списка задач и заметок. Этот класс должен иметь следующие методы:

addTask(TaskItem task) - для добавления задачи в список.
addNote(Note note) - для добавления заметки в список.
displayAll() - для отображения всех задач и заметок в списке.
getTask(int index) - для получения задачи по индексу.
getNote(int index) - для получения заметки по индексу.
Также создайте статический метод в классе "TaskList" для вывода общего количества задач в списке.

Добавьте дружественную функцию, которая позволит сравнивать задачи по их приоритету. Приоритет представить как перечисление (enum).

Перегрузите операторы сравнения (например, ==, !=, <, >), чтобы можно было сравнивать задачи и заметки.

Создайте консольное меню для пользователя, позволяющее добавлять задачи и заметки,
отмечать задачи как выполненные, отображать список задач и заметок, а также сравнивать задачи по приоритету.*/
enum class Priority {
    Low,
    Medium,
    High
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

    TaskItem getTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            return tasks[index];
        } else {
        // Возвращаем "пустую" задачу
        return TaskItem();
    }
}

  Note getNote(int index) {
    if (index >= 0 && index < notes.size()) {
        return notes[index];
    } else {
        // Возвращаем "пустую" заметку
        return Note();
    }
}

    static int getTotalTasks() {
        return tasks.size();
    }

    friend bool compareByPriority(const TaskItem& task1, const TaskItem& task2);
};

bool compareByPriority(const TaskItem& task1, const TaskItem& task2) {
    return task1.getPriority() > task2.getPriority();
}
