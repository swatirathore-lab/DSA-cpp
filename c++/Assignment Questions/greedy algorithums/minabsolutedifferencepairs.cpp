#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){ 
    vector<int> A={4,1,8,7};
    vector<int> B={2,3,6,5};
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int absdiff=0;
    for(int i=0;i<A.size();i++){
        absdiff=absdiff+abs(A[i]-B[i]);//abs is a function in cstdlib which returns the absolute value of the number passed to it
    }
    cout<<absdiff<<endl;

}