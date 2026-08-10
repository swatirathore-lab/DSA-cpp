#include<iostream>
#include <vector>
#include <algorithm>//for sort function
using namespace std;
bool compare(pair<double,int>p1,pair<double,int>p2){
    return p1.first>p2.first;
}
void fractionalknapsack(vector<int> value,vector<int> weight,int W){
    int n=value.size();
    vector<pair<double,int>> ratio(n,make_pair(0.0,0));
    for(int i=0;i<n;i++){
        double r=value[i]/(double)weight[i];
        ratio[i]=make_pair(r,i);
    }
    sort(ratio.begin(),ratio.end(),compare);//descending order of ratio
    int ans=0;
    for(int i=0;i<n;i++){
        int idx=ratio[i].second;
        if(weight[idx]<=W){
            ans=ans+value[idx];
            W=W-weight[idx];
        }
        else{
            ans=ans+(ratio[idx].first* W);
            W=0;
            break;
        }
    }
    cout<<ans<<endl;
}
int main() {
    vector<int> value={60,100,120};
    vector<int> weight={10,20,30};
    int W=50;
    fractionalknapsack(value,weight,W);
}
