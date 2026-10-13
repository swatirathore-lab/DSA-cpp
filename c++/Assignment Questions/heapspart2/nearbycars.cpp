#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Car {
    public://// FIX 1: members are private by default in a class

    int idx;
    int distsqr;
    Car(int idx,int distsqr){
        this->idx=idx;
        this->distsqr=distsqr;
    }
    bool operator<(const Car &obj) const {
        return this->distsqr>obj.distsqr; // FIX 2: "dist" -> "distsqr"
                                              // FIX 3: "<" -> ">" so the priority_queue becomes a min-heap
    }
};
    


void nearbycars(vector<pair<int,int>> pos,int k ){
    vector<Car> cars;
    for(int i=0;i<pos.size();i++){
        int distsqr=(pos[i].first*pos[i].first)+(pos[i].second*pos[i].second);// FIX 4: first/second are data members, not functions
        cars.push_back(Car(i,distsqr));// FIX 5: push_back takes one Car object

    }
    priority_queue<Car> pq(cars.begin(),cars.end());
    for(int i=0;i<k;i++){
        cout<<"car"<<pq.top().idx<<endl;
        pq.pop();
    }
}
int main(){
    vector<pair<int,int>> pos;
    pos.push_back(make_pair(3,3));// FIX 6: make_pair(...) uses parentheses, not braces
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));
    int k=2;
    nearbycars(pos,k);
    return 0;
}