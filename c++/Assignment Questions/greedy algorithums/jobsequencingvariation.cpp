#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class job {
    public:
    int idx;
    int deadline;
    int profit;
    job(int idx,int deadline,int profit){
        this->idx=idx;
        this->deadline=deadline;
        this->profit=profit;
    }
};
int maxprofit(vector<pair<int,int>> pairs){
    int n=pairs.size();
    vector <job> jobs;
    for(int i=0;i<n;i++){
        // BUG: was "pairs.emplace_back(...)" -> pushing into wrong vector,
        // "jobs" stayed empty forever. Must push into "jobs".
        jobs.emplace_back(i,pairs[i].first,pairs[i].second);//jobs hoga pairs nahi

    }
    sort(jobs.begin(),jobs.end(),[](job &a,job &b){
        return a.profit>b.profit;//descending order
    });
    cout<<"selecting jobs"<<jobs[0].idx<<endl;
    int profit=jobs[0].profit;
    int setdeadline=2;
    for(int i=1;i<n;i++){//1 se satrt hai****
        if(jobs[i].deadline>setdeadline){
            cout<<"selecting jobs"<<jobs[i].idx<<endl;
            profit=profit+jobs[i].profit;
            setdeadline++;
        }
       
    }
    cout<<"max profit is "<<profit<<endl;
    return profit;


}
int main(){
    int n=4;
    vector<pair<int,int>> jobs(n,make_pair(0,0));
    jobs[0]=make_pair(4,20);
    jobs[1]=make_pair(1,10);        
    jobs[2]=make_pair(1,40);
    jobs[3]=make_pair(1,30);
    maxprofit(jobs);
    return 0;
}