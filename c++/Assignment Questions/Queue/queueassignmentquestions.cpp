#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*
 * Question 3: Reverse first K elements of a queue
 *
 * Given an integer K and a queue of integers, reverse the order
 * of the first K elements of the queue, leaving the other elements
 * in the same relative order.
 *
 * Only standard queue operations allowed:
 * - push(x): Add an item x to rear of queue
 * - pop(): Remove an item from front of queue
 * - size(): Returns the number of elements in the queue
 * - front(): Finds front item
 *
 * Example:
 * Input: Queue is [1, 2, 3, 4, 5] & K = 3
 * Output: [3, 2, 1, 4, 5]
 * Explanation: After reversing the first 3 elements, the rest
 * stay in their original relative order.
 */
void reversekelements(queue<int> &q, int k){
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    int remaining = q.size() - k;
    for(int i=0;i<remaining;i++){
        q.push(q.front());
        q.pop();    
    }

}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);  
    q.push(5);
    int k = 3;
    reversekelements(q, k);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }


}