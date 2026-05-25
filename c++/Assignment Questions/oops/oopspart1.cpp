#include <iostream>
using namespace std;
class student {
    private:
    int id;
    string name;
    public:
    void display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
    }
    void setter(int i, string n)
    {
        id=i;
        name=n;
    }
    //getter functions
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
};
class user {
    private:
    int id;
    string name;
    string password;
    public:
    void display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Password: "<<password<<endl;
    }
    void setter(int i, string n, string p)
    {
        id=i;
        name=n;
        password=p;
    }
    //getter functions

    int getId()
    {
        return id;
    }  
    string getName()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }
};
//basics
class car {
    //constructor
    public:
    car(string b, string m, int y)
    {
        brand=b;
        model=m;
        year=y;
    }
    private:
    string brand;
    string model;
    int year;
    public:
    void display()
    {
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;
    }
    void setter(string b, string m, int y)
    {
        brand=b;
        model=m;
        year=y;
    }
};
//encapsulation is one of the fundamental principles of object-oriented programming (OOP). It refers to the bundling of data and methods that operate on that data within a single unit, typically a class. Encapsulation helps to protect the data from unauthorized access and modification by restricting access to the internal state of an object. This is achieved through the use of access specifiers such as private, protected, and public. By encapsulating data and methods within a class, we can create objects that have well-defined interfaces and can be easily maintained and reused.
class employee {
    private:
    int id;
    string name;
    public:
    void display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
    }
    void setter(int i, string n)
    {
        id=i;
        name=n;
    }
};

//constructors are special member functions that are automatically called when an object of a class is created. They are used to initialize the data members of the class. A constructor has the same name as the class and does not have a return type. It can be defined with or without parameters. If a constructor is defined without parameters, it is called a default constructor. If a constructor is defined with parameters, it is called a parameterized constructor. Constructors can also be overloaded, meaning that multiple constructors can be defined with different parameter lists.
class person {
    private:
    string name;
    int age;
    public:
    //constructor without parameters-non parameterized constructor
    person()
    {
        name="Unknown";
        age=0;
    }
    //constructor
    person(string n, int a)
    {
        this->name=n;//this is a parameterized constructor that initializes the name and age of the person object when it is created. The constructor takes two parameters, a string for the name and an integer for the age, and assigns them to the corresponding data members of the class. This allows us to create person objects with specific names and ages right from the start.
        this->age=a;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
//practice question
class user1 {
    private:
    int id;
    string password;
    public:
    string username;
    user1(int i)
    {
        id=i;
    }
    void setter(string p)
    {
        password=p;
    }
    string getusername()
    {
        return username;
    }
};
//copy constructor is a special constructor in C++ that is used to create a new object as a copy of an existing object. It is called when an object is passed by value, returned from a function, or explicitly copied using the assignment operator. The copy constructor takes a reference to an object of the same class as its parameter and creates a new object with the same values as the original object. If a copy constructor is not defined in a class, the compiler will generate a default copy constructor that performs a shallow copy of the object's data members.
class car1 {
    public:
    string name;
    string color;
    car1(string n, string c)//parameterized constructor
    {
        name = n;
        color = c;
    }
    //custom copy constructor
    car1(car1 &original)
    {
        name = original.name;
        color = original.color;
    }
};
//shallow and deep copy are two different ways of copying objects in C++. A shallow copy creates a new object that is a copy of the original object, but it only copies the values of the data members. If the data members are pointers, then both the original and the copied object will point to the same memory location, which can lead to issues such as double deletion. On the other hand, a deep copy creates a new object that is a copy of the original object, but it also creates new memory for any pointers and copies the values of the data members to that new memory. This ensures that the original and copied objects are completely independent of each other and can be safely modified without affecting each other.
class car2 {
    public:
    string name;
    string color;
    int *mileage;
    car2(string n, string c)//parameterized constructor
    {
        name = n;
        color = c;
        mileage = new int(0); // Initialize the pointer with a new integer
        *mileage = 12;
    }
    //custom copy constructor for deep copy
    car2(car2 &original)
    {
        name = original.name;
        color = original.color;
        mileage = new int(*original.mileage); // Allocate new memory and copy the value deep copy of mileage
    }
};
//deconstructor is a special member function in C++ that is automatically called when an object goes out of scope or is explicitly deleted. It is used to perform cleanup operations, such as releasing resources or memory that was allocated by the object. A destructor has the same name as the class, but it is preceded by a tilde (~) and does not have a return type. It cannot take any parameters and cannot be overloaded. The destructor is typically used to free any dynamically allocated memory or to close any open files or network connections that the object may have created during its lifetime.
class car3 {
    public:
    string name;
    string color;
    int *mileage;
    car3(string n, string c)//parameterized constructor
    {
        name = n;
        color = c;
        mileage = new int(0); // Initialize the pointer with a new integer
        *mileage = 12;
    }
    //custom copy constructor for deep copy
    car3(car3 &original)
    {
        name = original.name;
        color = original.color;
        mileage = new int(*original.mileage); // Allocate new memory and copy the value deep copy of mileage
    }
    //deconstructor
    ~car3()
    {
        if(mileage!=NULL)
        delete mileage; // Free the dynamically allocated memory for mileage
        mileage = NULL; // Set the pointer to NULL after deleting
    }
};
//inheritance is a fundamental concept in object-oriented programming (OOP) that allows a new class (called a derived class or child class) to inherit properties and behaviors (data members and member functions) from an existing class (called a base class or parent class). The derived class can then add its own unique properties and behaviors, or override the inherited ones to provide specific implementations. Inheritance promotes code reusability and establishes a natural hierarchical relationship between classes, making it easier to manage and organize code. It also enables polymorphism, allowing objects of different classes to be treated as objects of a common base class, which can simplify code and enhance flexibility.
class animal {
    public:
    void eat()
    {
        cout<<"Animal is eating"<<endl;
    }
};  
class dog : public animal {
    public:
    void bark()
    {
        cout<<"Dog is barking"<<endl;
    }
};
//mode of inheritance: public, private, protected
//In public inheritance, the public members of the base class become public members of the derived class
//In private inheritance, the public members of the base class become private members of the derived class
//In protected inheritance, the public members of the base class become protected members of the derived class
//types of inheritance: single, multiple, multilevel, hierarchical, hybrid
//muiltilevel inheritance is a type of inheritance where a class is derived from another class, which is also derived from another class. In this type of inheritance, there is a chain of inheritance where each class inherits from the previous class in the chain. For example, if we have three classes A, B, and C, where B is derived from A and C is derived from B, then we have a multilevel inheritance hierarchy. In this case, class C will inherit the properties and behaviors of both class A and class B, allowing it to access and use the members of both classes. Multilevel inheritance can be useful for creating complex class hierarchies and promoting code reuse, but it can also lead to issues such as ambiguity if multiple classes in the hierarchy have members with the same name.
class A {
    public:
    void displayA()
    {
        cout<<"Class A"<<endl;
    }
};
class B : public A {
    public:
    void displayB()
    {
        cout<<"Class B"<<endl;
    }
};
class C : public B {
    public:
    void displayC()
    {
        cout<<"Class C"<<endl;
    }
};
//multtiple inheritance is a type of inheritance where a class can inherit
class teacher{
    public:
    int salary;
    string subject;
    void displayteacher()
    {
        cout<<"Salary: "<<salary<<endl;
        cout<<"Subject: "<<subject<<endl;
    }
};
class student1{
    public:
    int rollno;
    string course;
    void displaystudent()
    {
        cout<<"Roll No: "<<rollno<<endl;
        cout<<"Course: "<<course<<endl;
    }
};
class teachingassistant : public teacher, public student1 {
    public:
    void displayta()
    {
        displayteacher();
        displaystudent();
    }
};
//heirachal inheritance is a type of inheritance where multiple classes are derived from a single base class. In this type of inheritance, there is a single base class that serves as the parent class for multiple derived classes. Each derived class can have its own unique properties and behaviors, while still inheriting the common properties and behaviors from the base class. For example, if we have a base class called "Animal" and multiple derived classes such as "Dog", "Cat", and "Bird", all of these derived classes can inherit the common properties and behaviors of the "Animal" class, while also having their own specific properties and behaviors that differentiate them from each other. Hierarchical inheritance can be useful for creating a clear and organized class structure, but it can also lead to issues such as code duplication if multiple derived classes have similar properties and behaviors.
class animal1 {
    public:
    void eat()
    {
        cout<<"Animal is eating"<<endl;
    }
    void swim()
    {
        cout<<"Animal is swimming"<<endl;
    }
    void breathe()
    {
        cout<<"Animal is breathing"<<endl;
    }
};
class fish : public animal1 {
    public:
    void displayfish()
    {
        eat();
        swim();
        breathe();
    }
};
class bird : public animal1 {
    public:
    void displaybird()
    {
        eat();
        breathe();
    }
};
class mammal : public animal1 {
    public:
    void displaymammal()
    {
        eat();
        breathe();
    }
};
//hybrid inheritance is a type of inheritance that combines multiple types of inheritance, such as single, multiple, and multilevel inheritance. In hybrid inheritance, a class can inherit
//polymorphism is a fundamental concept in object-oriented programming (OOP) that allows objects of different classes to be treated as objects of a common base class. It enables a single interface to represent different types of objects, allowing for flexibility and extensibility in code design. Polymorphism can be achieved through function overloading, operator overloading, and inheritance. Inheritance allows derived classes to override base class methods, providing their own implementation while still being treated as instances of the base class. This allows for dynamic method dispatch, where the appropriate method is called based on the actual type of the object at runtime, rather than the type of the reference variable. Polymorphism promotes code reusability and helps to create more maintainable and scalable software systems.
//compile time polymorphosim is achieved through function overloading and operator overloading, while runtime polymorphism is achieved through inheritance and virtual functions. In compile time polymorphism, the decision of which function to call is made at compile time based on the number and types of arguments passed to the function. In runtime polymorphism, the decision of which function to call is made at runtime based on the actual type of the object being referred to by a base class pointer or reference. This allows for more flexible and dynamic behavior in code, as different objects can respond differently to the same function call based on their specific implementations.
//function overloading is a feature in C++ that allows multiple functions to have the same name but different parameter lists. This means that you can define multiple functions with the same name, as long as they have different types or numbers of parameters. The compiler determines which function to call based on the arguments passed to the function at compile time. Function overloading can improve code readability and maintainability by allowing you to use the same function name for related operations, while still providing flexibility in how those operations are performed based on the specific parameters passed to the function.
class print {
    public:
    void display(int i)
    {
        cout<<"Integer: "<<i<<endl;
    }
    void display(string s)
    {
        cout<<"String: "<<s<<endl;
    }   
};
//operator overloading is a feature in C++ that allows you to define custom behavior for operators when they are used with user-defined types (classes). This means that you can overload operators such as +, -, *, /, and others to work with objects of your classes in a way that makes sense for those objects. Operator overloading can improve code readability and maintainability by allowing you to use familiar operators with your own types, rather than having to call member functions or use other syntax to perform operations on those types. However, it is important to use operator overloading judiciously and ensure that the overloaded operators behave in a way that is intuitive and consistent with their usual meanings, to avoid confusion for other developers who may be using your code.
class complex {
    public:
    int real;
    int imag;
    complex(int r, int i) {
        real = r;
        imag = i;
    }
    void show() {
        cout << real << " + " << imag << "i" << endl;
    }
    // Overload the + operator to add two complex numbers
    complex operator+(const complex& other) {
        int r = this->real + other.real;
        int i = this->imag + other.imag;
        return complex(r, i);
    }
};

int main ()
{

    user u1;//getter functions that allows us to set the values of these data members, and getter functions getId(), getName(), and getPassword() that allow us to retrieve their values. This allows us to control access to the data members while still providing a way to set and retrieve their values as needed.
    u1.setter(201, "Jane Doe", "secret123");
    u1.display();
    employee e1;//encapsulation is demonstrated in the employee class where the data members id and name are declared as private. This means that they cannot be accessed directly from outside the class. Instead, we have public member functions setter() and display() that allow us to set the values of id and name and display them respectively. By using encapsulation, we can protect the data members from unauthorized access and modification, ensuring that they are only accessed through the defined member functions.
    e1.setter(101, "John Doe");
    e1.display();
    person p;//non parameterized constructor is called when we create an object of the person class without providing any arguments. In this case, the default constructor initializes the name to "Unknown" and the age to 0. When we call the display() function for this object, it will output "Name: Unknown" and "Age: 0".
    p.display();
    person p1("Alice", 25);//parameterized constructor is called when we create an object of the person class and provide arguments for the name and age. In this case, the parameterized constructor initializes the name to "Alice" and the age to 25. When we call the display() function for this object, it will output "Name: Alice" and "Age: 25".
    p1.display();
    car1 c1("maruti800","white");//copy constructor is called when we create a new object c2 and initialize it with an existing object c1. The copy constructor creates a new object c2 that is a copy of c1, meaning that it has the same values for the name and color data members. When we call the display() function for c2, it will output "Brand: maruti800" and "Color: white", which are the same values as c1. This demonstrates how the copy constructor allows us to create new objects that are copies of existing objects, which can be useful in situations where we want to create multiple objects with similar properties.
    car1 c2(c1);
    cout<<c2.name<<endl;//maruti800
    cout<<c2.color<<endl;//white as default copy constructor performs a shallow copy of the object's data members, which means that it copies the values of the data members from the original object to the new object. In this case, since the data members are of type string, which is a class in C++, the
    //shallow and deep copy will have the same effect because the string class manages its own memory and handles copying correctly. Therefore, both c1 and c2 will have their own separate copies of the name and color data members, and modifying one will not affect the other.
    car2 c3("Honda Civic", "Red");
    car2 c4(c3); // This will call the copy constructor for car2
    cout<<c4.name<<endl;//Honda Civic
    cout<<c4.color<<endl;//Red
    *c4.mileage =18;
    cout<<*c3.mileage<<endl;//18 if deep copy has not been implemented, both c3 and c4 will point to the same memory location for mileage, so changing the value of mileage through c4 will also change the value of mileage for c3. This is because the default copy constructor performs a shallow copy, which means that it copies the values of the data members from the original object to the new object, but it does not create new memory for any pointers. Therefore, both c3 and c4 will have their mileage pointer pointing to the same memory location, and modifying one will affect the other.
    cout<<*c4.mileage<<endl;//18
    //if deep copy has been implemented, the copy constructor for car2 would create a new memory location for the mileage pointer and copy the value of mileage from c3 to that new memory location. This means that c3 and c4 would have their own separate mileage pointers, and modifying one would not affect the other. Therefore, if deep copy has been implemented, changing the value of mileage through c4 would not change the value of mileage for c3, and both would have their own independent values for mileage.
    dog d;
    d.eat(); // Inherited from animal class
    d.bark(); // Defined in dog class
    C c;
    c.displayA(); // Inherited from class A 
    c.displayB(); // Inherited from class B
    c.displayC(); // Defined in class C
    teachingassistant ta;
    ta.salary = 50000;
    ta.subject = "Mathematics";
    ta.rollno = 12345;
    ta.course = "Computer Science";
    ta.displayta(); // Displays both teacher and student information
    fish f;
    f.displayfish(); // Displays eating, swimming, and breathing behaviors
    bird b;
    b.displaybird(); // Displays eating and breathing behaviors
    mammal m;
    m.displaymammal(); // Displays eating and breathing behaviors
    print pr;
    pr.display(42); // Calls the display function for integers
    pr.display("Hello"); // Calls the display function for strings
    complex c5(2,3);
    complex c6(4,5);
    complex c7 = c5 + c6; // Uses the overloaded + operator to add two complex numbers
    c7.show(); // Displays the result of the addition, which should be "6 +

    return 0;

}
