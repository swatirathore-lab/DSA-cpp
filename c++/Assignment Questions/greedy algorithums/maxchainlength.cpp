#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;//****signs to remmeber */
}
void maxlengthchainofpairs(vector<pair<int,int>> pairs){

    int n=pairs.size();
    sort(pairs.begin(),pairs.end(),compare);//begin likhna hai end likhne hai remmeber
    int count=1;
    int currmax=pairs[0].second;
    for(int i=1;i<n;i++){
        if(pairs[i].first>currmax){
            count++;
            currmax=pairs[i].second;
        }

    }
    cout<<count<<endl;

    
}
int main(){
    vector<pair<int,int>> pairs={{5,24},{39,60},{5,28},{27,40},{50,90}};
    maxlengthchainofpairs(pairs);
}