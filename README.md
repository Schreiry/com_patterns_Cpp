
<div align="center">
<h1> Design Patterns: Singleton and Factory Method</h1>
</div>
<div align = "center">
<h3> Prologue</h3>
</div>

In the world of software development, design patterns are essential tools that help developers solve common problems in a structured and efficient manner. Design patterns provide reusable solutions to recurring problems, making code more maintainable, scalable, and understandable.

In this article, we will explore two fundamental design patterns: **Singleton** and **Factory Method**. We will also see how these patterns can be applied in a real-world scenario, such as managing a cafe, to demonstrate their practical utility.

>The code provided is a C++ implementation that showcases the use of these patterns. We will break down the code into sections, explaining each part in detail, and discuss the theory behind the patterns. By the end of this article, you will have a clear understanding of how these patterns work and why they are beneficial in software design.


## **Chapter 1: Singleton Pattern**

### **Theory of Singleton Pattern**

The **Singleton** pattern is a creational design pattern that ensures a class has only **one instance** while providing a **global point of access** to that instance. This is particularly useful when exactly one object is needed to coordinate actions across a system, such as a configuration manager, a connection pool, or, in our case, a **cafe manager**.

The key characteristics of the **Singleton** pattern are:

- **Private Constructor** : The constructor of the Singleton class is made private to prevent external instantiation.
- **Static Instance** : A static member variable holds the single instance of the class.
- **Static Method** : A static method (usually named `getInstance`) provides access to the single instance. If the instance does not exist, it creates one; otherwise, it returns the existing instance.

### **Singleton in the Code**

In the provided code, the `Cafe` class is implemented as a **Singleton**. Let's break it down:

```cpp
class Cafe {
private:
    static Cafe* instance;  // Static instance of the Cafe class
    Cafe() {}  // Private constructor to prevent external instantiation

public:
    static Cafe* getInstance() {
        if (instance == nullptr) {
            instance = new Cafe();  // Create a new instance if it doesn't exist
        }
        return instance;  // Return the single instance
    }

    void open() {
        std::cout << "Cafe is open!" << std::endl;
    }

    void close() {
        std::cout << "Cafe is closed!" << std::endl;
    }
};

Cafe* Cafe::instance = nullptr;  // Initialize the static instance to nullptr
```

#### **Explanation:**
- **Private Constructor**: The constructor of the `Cafe` class is private, meaning no other class can create an instance of `Cafe` directly.
- **Static Instance**: The `instance` variable is static, ensuring that there is only **one instance** of the `Cafe` class throughout the program.
- **Static Method**: The `getInstance` method checks if the `instance` is `nullptr`. If it is, it creates a new `Cafe` object. Otherwise, it returns the existing instance.

This ensures that no matter how many times `getInstance` is called, the same instance of `Cafe` is returned, maintaining a single point of control for the cafe's operations.


## **Chapter 2: Factory Method Pattern**

### **Theory of Factory Method Pattern**

The **Factory Method** pattern is another creational design pattern that provides an **interface for creating objects in a superclass** but allows subclasses to alter the type of objects that will be created. This pattern is useful when a class cannot anticipate the type of objects it needs to create or when the creation process should be delegated to subclasses.

The key components of the **Factory Method** pattern are:

- **Product**: An abstract class or interface that defines the type of objects the factory method creates.
- **Concrete Product**: A class that implements the `Product` interface.
- **Creator**: An abstract class or interface that declares the factory method, which returns an object of type `Product`.
- **Concrete Creator**: A class that implements the factory method to produce a specific `Concrete Product`.

### **Factory Method in the Code**

In the code, the **Factory Method** pattern is used to create different types of dishes (`Pizza` and `Pasta`). Let's analyze the implementation:

```cpp
class Dish {
public:
    virtual void prepare() = 0;  // Pure virtual function
};

class Pizza : public Dish {
public:
    void prepare() override {
        std::cout << "Preparing Pizza..." << std::endl;
    }
};

class Pasta : public Dish {
public:
    void prepare() override {
        std::cout << "Preparing Pasta..." << std::endl;
    }
};

class DishFactory {
public:
    virtual Dish* createDish() = 0;  // Factory method
};

class PizzaFactory : public DishFactory {
public:
    Dish* createDish() override {
        return new Pizza();  // Create a Pizza object
    }
};

class PastaFactory : public DishFactory {
public:
    Dish* createDish() override {
        return new Pasta();  // Create a Pasta object
    }
};
```

#### **Explanation:**
- **Product** : The `Dish` class is an abstract base class with a pure virtual function `prepare`.
- **Concrete Products** : The `Pizza` and `Pasta` classes inherit from `Dish` and implement the `prepare` method.
- **Creator** : The `DishFactory` class declares the factory method `createDish`.
- **Concrete Creators** : The `PizzaFactory` and `PastaFactory` classes implement the `createDish` method to return instances of `Pizza` and `Pasta`, respectively.

This pattern allows the **creation of dishes** to be flexible and extensible. If a new dish type is added, only a **new factory** needs to be created without modifying the existing code.

---

## **Chapter 3 : Cafe Scenario**

### **Main Function Implementation**

```cpp
int main() {
    Cafe* cafe = Cafe::getInstance();  // Get the Singleton instance
    cafe->open();

    // Prepare dishes using Factory Method
    DishFactory* pizzaFactory = new PizzaFactory();
    Dish* pizza = pizzaFactory->createDish();
    pizza->prepare();

    DishFactory* pastaFactory = new PastaFactory();
    Dish* pasta = pastaFactory->createDish();
    pasta->prepare();

    cafe->close();

    // Clean up
    delete pizza;
    delete pasta;
    delete pizzaFactory;
    delete pastaFactory;

    return 0;
}
```

---

## **Epilogue**

Design patterns like **Singleton** and **Factory Method** are powerful tools that help developers write clean, maintainable, and scalable code.

- **Singleton** ensures that a class has only one instance, providing a global point of access.
- **Factory Method** delegates object creation to subclasses, making the system more flexible.

In the **cafe scenario**, these patterns work together seamlessly:
- The **Singleton** manages the cafe's operations.
- The **Factory Method** handles dish creation.

By using design patterns, we can improve code quality, make it more understandable, and facilitate teamwork in software development.
























