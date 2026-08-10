#include <iostream>
#include <vector>
using namespace std;
void maximumactivities(vector<int> start, vector<int> end){
    int count=1;
    cout<<"selecting A0"<<endl;
    int currmax=end[0];
    for(int i=0;i<start.size();i++){
        if(start[i]>=currmax){
            cout<<"selecting A"<<i<<endl;
            count++;
            currmax=end[i];
        }
    }
    cout<<count<<endl;
}
int main(){
    vector<int> start={1,3,0,5,8,5};
    vector<int> end={2,4,6,7,9,9};
    maximumactivities(start,end);
}
