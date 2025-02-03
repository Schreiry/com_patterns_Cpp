// Directivbe space : 

#include <iostream>
#include <vector>
#include <algorithm>


//-=-=-=-=-=-=-=-=-

using namespace std;

//-==-=--=-=-=-=-=-   



// ------------------- Singleton -------------------

//class Singleton {
//private:
//    static Singleton* instance;
//    Singleton() {}  // Приватный конструктор
//
//public:
//    static Singleton* getInstance() {
//        if (instance == nullptr) {
//            instance = new Singleton();
//        }
//        return instance;
//    }
//
//    void doSomething() {
//        cout << "Doing something!" << endl;
//    }
//};
//
//Singleton* Singleton::instance = nullptr;
//
//int main() {
//    Singleton::getInstance()->doSomething();
//    return 0;
//}


// ------------------- Factory Method -------------------

//class Product {
//public:
//    virtual void use() = 0;
//};
//
//class ConcreteProductA : public Product {
//public:
//    void use() override {
//        cout << "Using Product A" << endl;
//    }
//};
//
//class ConcreteProductB : 
//public Product {
//public:
//    void use() override {
//        cout << "Using Product B" << endl;
//    }
//};
//
//class Creator {
//public:
//    virtual Product* createProduct() = 0;
//};
//
//class ConcreteCreatorA : public Creator {
//public:
//    Product* createProduct() override {
//        return new ConcreteProductA();
//    }
//};
//
//class ConcreteCreatorB : public Creator {
//public:
//    Product* createProduct() override {
//        return new ConcreteProductB();
//    }
//};
//
//int main() {
//    Creator* creator = new ConcreteCreatorA();
//    Product* product = creator->createProduct();
//    product->use();
//
//    delete product;
//    delete creator;
//    return 0;
//}


// ------------------- cafe -------------------

// Singleton для управления кафе
class Cafe {
private:
    static Cafe* instance;
    Cafe() {}

public:
    static Cafe* getInstance() {
        if (instance == nullptr) {
            instance = new Cafe();
        }
        return instance;
    }

    void open() {
        cout << "Cafe is open!" << endl;
    }

    void close() {
        cout << "Cafe is closed!" << endl;
    }
};

Cafe* Cafe::instance = nullptr;

// Observer для уведомлений
class Observer {
public:
    virtual void update(const string& message) = 0;
};

class Customer : public Observer {
private:
    string name;

public:
    Customer(const string& name) : name(name) {}

    void update(const string& message) override {
        cout << name << " received message: " << message << endl;
    }
};

// Factory Method для создания блюд
class Dish {
public:
    virtual void prepare() = 0;
};

class Pizza : public Dish {
public:
    void prepare() override {
        cout << "Preparing Pizza..." << endl;
    }
};

class Pasta : public Dish {
public:
    void prepare() override {
        cout << "Preparing Pasta..." << endl;
    }
};

class DishFactory {
public:
    virtual Dish* createDish() = 0;
};

class PizzaFactory : public DishFactory {
public:
    Dish* createDish() override {
        return new Pizza();
    }
};

class PastaFactory : public DishFactory {
public:
    Dish* createDish() override {
        return new Pasta();
    }
};

int main() {
    Cafe* cafe = Cafe::getInstance();
    cafe->open();

    // Создаем клиентов
    Customer customer1("Alice");
    Customer customer2("Bob");

    // Уведомляем клиентов
    customer1.update("Welcome to our cafe!");
    customer2.update("Today's special: Pizza and Pasta!");

    // Готовим блюда
    DishFactory* pizzaFactory = new PizzaFactory();
    Dish* pizza = pizzaFactory->createDish();
    pizza->prepare();

    DishFactory* pastaFactory = new PastaFactory();
    Dish* pasta = pastaFactory->createDish();
    pasta->prepare();

    cafe->close();

    delete pizza;
    delete pasta;
    delete pizzaFactory;
    delete pastaFactory;

    return 0;
}