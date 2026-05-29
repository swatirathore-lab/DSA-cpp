#include <iostream>
using namespace std;
//functiion overriding is a feature in c++ that allows a derived class to provide a specific implementation of a function that is already defined in its base class. When a function in the derived class has the same name, return type, and parameters as a function in the base class, the function in the derived class overrides the function in the base class. This means that when you call the function on an object of the derived class, the implementation in the derived class will be executed instead of the one in the base class. Function overriding is typically used to provide specific behavior for a derived class while still maintaining a common interface defined by the base class.
class parent {
    public:
    void show() {
        cout << "This is the parent class." << endl;
    }
};
class child : public parent {
    public:
    void show() {
        cout << "This is the child class." << endl; 
    }
};
//virtual functions are a key feature in C++ that allow for dynamic (runtime) polymorphism. A virtual function is a member function in a base class that you can override in a derived class. When you declare a function as virtual in the base class, it tells the compiler to support late binding on this function. This means that when you call the function through a pointer or reference to the base class, the version of the function that gets executed will be determined at runtime based on the actual type of the object being pointed to, rather than the type of the pointer or reference. This allows for more flexible and extensible code, as you can add new derived classes without modifying existing code that uses pointers or references to the base class.
class parent1 {
    public:
    virtual void show() {
        cout << "This is the parent class." << endl;
    }
};// In this example, the show() function in the parent class is declared as virtual. This means that if we have a pointer or reference to the parent class that points to an object of the child class, calling show() will execute the child class's version of the function instead of the parent class's version.
class child1 : public parent1 {
    public:
    void show() {
        cout << "This is the child class." << endl; 
    }
};
//abstraction is a fundamental concept in object-oriented programming that focuses on hiding the complex implementation details of a system and exposing only the necessary and relevant features to the user. It allows developers to create models that represent real-world entities while keeping the internal workings hidden. In C++, abstraction can be achieved through the use of abstract classes and pure virtual functions. An abstract class is a class that cannot be instantiated and is typically used as a base class for other classes. A pure virtual function is a virtual function that has no implementation in the base class and must be overridden in any derived class. This allows for a clear separation between the interface (what the class does) and the implementation (how it does it), making code easier to maintain and extend.
class shape {
    public:
    virtual void draw() = 0; // Pure virtual function, making this an abstract class
};
class circle: public shape{
    public:
    void draw() {
        cout<< "Drawing a circle." << endl;
    }
};
class square: public shape{
    public:
    void draw() {
        cout<< "Drawing a square." << endl;
    }
};
//static keyword in C++ is used to declare variables, functions, and class members that are shared among all instances of a class. When a member is declared as static, it belongs to the class rather than any specific object. This means that there is only one copy of the static member, and it is shared by all objects of the class. Static members can be accessed using the class name or through an object of the class. Static functions can only access static members and cannot access non-static members of the class. Static variables are often used for counting instances of a class or for defining constants that are shared across all instances.
void counter() {
    //count=0; // This will reset count to 0 every time the function is called, which is not the intended behavior for a counter. Instead, we should declare count as static to maintain its value across function calls.
    static int count=0; // Static variable
    count++;
    cout<<"count : "<<count<<endl;
}
class example{
    public:
    // int x=0;
    static int x; // Static member variable declaration
};
int example::x=0; // Static member variable definition and initialization important to define and initialize static member variables outside the class definition, as they are shared among all instances of the class and need to be allocated memory separately from the class instances.
//static objects are objects that are created with static storage duration, meaning they exist for the entire duration of the program. They are typically declared at the global scope or as static members of a class. Static objects are initialized only once, and their memory is allocated at compile time. They can be accessed directly without needing to create an instance of the class. Static objects are useful for maintaining state or data that needs to be shared across multiple instances of a class or throughout the program.
class example1 {
    public:
    example1() {
        cout<<"Constructor called. Current count: "<<endl;   
    }
    ~example1() {
        cout<<"Destructor called. Current count: "<<endl;   
    }   
    
};
//friend functions & classes are a feature in C++ that allows a function or an entire class to access the private and protected members of another class. A friend function is a non-member function that is declared as a friend of a class, giving it access to the class's private and protected members. A friend class is a class that is declared as a friend of another class, allowing all member functions of the friend class to access the private and protected members of the other class. Friend functions and classes are useful for situations where you want to allow certain functions or classes to have special access to the internals of another class without making those members public.
class A1 {
    
    string secret ="secret data";
    friend class B1; // Declare class B as a friend of class A b kke pass a ke data ki acess aaygi
};
class B1 {
    public:
    void revealSecret(A1 &a) {
        cout<<"Revealing secret: "<<a.secret<<endl; // This will now work because class B is declared as a friend of class A.
    }
};
// practice questions
class A {
    public:
    A() { std::cout << "Constructor A" << std::endl; }
    ~A() {std::cout <<"Destructor A" << std::endl;}
};    
class B:public A{
    public:
    B() { std::cout<<"constructor B"<<std::endl;}
    ~B() {std::cout<<"deconstructor B"<<std::endl;}
};    
//practice questions
class Base {
public:
    virtual void print() {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        cout << "Derived" << endl;
    }
};

int main() {
    parent p;
    child c;
    p.show(); // Output: This is the parent class.
    c.show(); // Output: This is the child class.
    child1 child1;
    parent1 *ptr;
    ptr = &child1;// Pointing to child class object using base class pointer runt time binding
    ptr->show(); // Output: This is the child class. (due to virtual function) virtual function allows the program to determine at runtime which version of the show() function to call, based on the actual type of the object (child1) that ptr is pointing to, rather than the type of the pointer (parent1*).
    //shape s; // Error: cannot instantiate abstract class
    shape *s1 = new circle(); // Correct way to use abstract class: create object of derived class
    s1->draw(); // Output: Drawing a circle.
    delete s1;
    // Demonstrating static variable
    counter(); // Output: count : 1
    counter(); // Output: count : 1 (because count is a local variable and is reinitialized to 0 each time the function is called)  
    counter(); // Output: count : 1 (same reason as above)  
    // To maintain the count across function calls, we should declare count as static inside the counter function. This way, it will retain its value between calls and increment correctly.
    counter(); // Output: count : 1 (after changing count to static, it will now output count : 2, count : 3, etc. on subsequent calls) 
    counter(); // Output: count : 2 (same reason as above)  
    example eg1;// This will create an object of the example class and initialize x to 0
    cout<<"Value of x in eg1: "<<eg1.x<<endl; // Output: Value of x in eg1: 0
    example eg2;// This will create another object of the example class and initialize x to 0
    cout<<"Value of x in eg2: "<<eg2.x<<endl; // Output: Value of x in eg2: 0
    //now with static member variable, we can change the value of x using one object and it will reflect in all objects of the class since x is shared among all instances.
    example::x = 10; // Changing the value of static member variable x using the class name
    cout<<"Value of x in eg1 after change: "<<eg1.x<<endl; // Output: Value of x in eg1 after change: 10
    cout<<"Value of x in eg2 after change: "<<eg2.x++<<endl; // Output: Value of x in eg2 after change: 10 (post-increment, so it will show 10 first and then increment to 11)
    cout<<"Value of x in eg1 after eg2 change: "<<eg1.x<<endl; // Output: Value of x in eg1 after eg2 change: 11 (since x is static, the change made through eg2 will reflect in eg1 as well)   
    int a=0;
    if(a==0) {
        static example1 eg3; // This will create a static object of the example1 class. The constructor will be called when the object is created, and the destructor will be called when the program ends. 
    }
    cout<<"code ending..\n"; // The static object eg1 will be created only once and will exist until the end of the program. The constructor will be called after the static object is created, and the destructor will be called when the program ends.
    A1 a1;
    B1 b1;
    b1.revealSecret(a1); // Output: Revealing secret: secret data (
    //practice question
    B obj;
    //practice questions
    Base* b = new Derived();
    b->print();
    delete b;
    return 0;
}