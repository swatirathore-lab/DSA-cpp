#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void queuereversal(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

}
int main() {
    queue<int> q;
    for(int i=1;i<6;i++){
        q.push(i);
    }
    queuereversal(q);
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
