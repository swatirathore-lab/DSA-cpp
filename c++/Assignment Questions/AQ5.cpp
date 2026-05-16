#include <iostream>
using namespace std;
void areaofsquare() {
    int n;
    cout << "input value of sides" << endl;
    cin >> n;
    cout << "the area of the square is"<< n *n << endl;
}


void areaofcircle() {
    cout << "input radius" << endl;
    double r;
    cin >> r;
    cout << "the area of the circle is " << 3.14 * r * r << endl;
}

void simpleintrest(){
    int p,r,t;
    cout << "input value of p,r,t" << endl;
    cin >> p >> r >> t;
    cout << "the simple interest is " << (p*r*t)/100 << endl;
}

void totalcost() {
float pen;
float pencil;
float eraser;
cout<<"cost of pen"<<endl;
cin>>pen;
cout<<"cost of pencil"<<endl;
cin>>pencil;
cout<<"cost of eraser"<<endl;
cin>>eraser;
cout<<"total cost is "<< pen + pencil + eraser << endl;
}
int main() {
    areaofsquare();
    areaofcircle();
    simpleintrest();
    totalcost();
    return 0;
}