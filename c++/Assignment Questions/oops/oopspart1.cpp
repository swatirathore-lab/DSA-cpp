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
        mileage= original.mileage;//shallow copy of mileage pointer
       
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
    cout<<*c3.mileage<<endl;//12
    cout<<*c4.mileage<<endl;//18
    return 0;

}
