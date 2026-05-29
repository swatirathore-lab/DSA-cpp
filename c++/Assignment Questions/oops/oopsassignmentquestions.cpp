#include <iostream>
using namespace std;
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
    complex operator - ( complex & other) {
        int r = this->real - other.real;
        int i = this->imag - other.imag;
        return complex(r, i);
    }
};

class BankAccount {
    private:
    int accountNumber;
    int balance;
    public:
    BankAccount(int an,int bal){
        accountNumber=an;
        balance=bal;
    }
    void deposit(double amount){
        balance=balance+amount;
    };
    void withdraw(double amount){
        if(amount<balance){
            balance=balance-amount;
        }else {
            cout<<"no sufficient balance in the account"<<endl;
        }
        
    }
    double getBalance(){
        return balance;
    }
};
class person {
    protected:
    string name;
    int age;
    public:
    person(string n,int a){
        name=n;
        age=a;
    }
};
class student:public person{
    private:
    string studentID;
    public:
    student(string n,int a,string id):person(n,a){
        studentID =id;
    }
    void displayStudentInfo() {
        cout<<"name of a student is"<<this->name<<endl; 
        cout<<"age of a  student is"<<this->age<<endl;
        cout<<"student id of a student is"<<this->studentID<<endl;
    }

};

int main(){
    BankAccount myAccount(12345,500.0);
    myAccount.deposit(876);
    myAccount.withdraw(543);
    cout<<"current balance is"<<myAccount.getBalance()<<endl;
    student s("Alice",20,"s12345");
    s.displayStudentInfo();
    complex c1(9,7);
    complex c2(6,4);
    complex c3=c1-c2;
    c3.show();

    return 0;
   

}