#include <string>
#include <iostream>
using namespace std;
class Task {
public:
    // Чисто виртуальный метод для отображения информации о задаче
    virtual void display() = 0;

    // Чисто виртуальный метод для проверки, выполнена ли задача
    virtual bool isCompleted() = 0;

    // Чисто виртуальный метод для отметки задачи как выполненной
    virtual void markAsCompleted() = 0;
};

class TaskItem : public Task {
private:
    string title;       // Заголовок задачи
    string description; // Описание задачи
    bool completed;          // Флаг, указывающий, выполнена ли задача
};
