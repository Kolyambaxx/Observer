// Observer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

// Абстрактний спостерігач
class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
};

// Конкретний спостерігач
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(const std::string& message) override {
        std::cout << "Observer " << name << " received message: " << message << std::endl;
    }

private:
    std::string name;
};

// Суб'єкт (Спостерігаємий об'єкт)
class Subject {
public:
    // Додати спостерігача
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    // Видалити спостерігача
    void removeObserver(Observer* observer) {
        // Видалення спостерігача (для спрощення залишено без перевірок)
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Сповіщення всіх спостерігачів про зміну
    void notify(const std::string& message) {
        for (auto observer : observers) {
            observer->update(message);
        }
    }

private:
    std::vector<Observer*> observers;
};

int main() {
    // Створення спостерігачів
    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    // Створення спостерігаємого об'єкту (суб'єкта)
    Subject subject;

    // Додавання спостерігачів до суб'єкта
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    // Сповіщення спостерігачів про зміну стану
    subject.notify("Hello, observers!");

    // Видалення одного спостерігача
    subject.removeObserver(&observer1);

    // Знову сповіщення про зміну стану
    subject.notify("Another update!");

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
