#include <iostream>
#include <queue>
using namespace std;

void interleave2queues(queue<int> &org){ // & because we want to modify the original queue

    queue<int> first;

    int half = org.size()/2;
    // MISTAKE: originally used org.size() directly as the loop bound
    // below, while also popping org inside that same loop. size()
    // shrinks every iteration, so the loop ran an unpredictable
    // number of times. FIX: capture size in a variable BEFORE the
    // loop starts.

    for(int i=0; i<half; i++){
        // MISTAKE: originally wrote i<=half instead of i<half.
        // <= pushes one extra element into 'first' than intended.
        first.push(org.front());
        org.pop();
    }

    while(!first.empty()){
        org.push(first.front());
        first.pop();
        org.push(org.front());
        org.pop();
    }
}

int main(){
    queue<int> org;

    for(int i=1; i<=10; i++){
        // MISTAKE: originally wrote i<org.size() to fill an EMPTY
        // queue. size() is 0 before anything is pushed, so the
        // condition (0 < 0) was false immediately and the loop
        // never ran — org stayed empty forever.
        // FIX: use a fixed range, not the container's own size,
        // when the loop's job is to fill that container.
        org.push(i);
    }

    // MISTAKE: originally printed org here using front()+pop() in
    // a loop, which fully emptied org BEFORE calling
    // interleave2queues(org) below. front() only peeks, it doesn't
    // remove — but looping front() without pop() just reprints the
    // same element N times, so pop() is needed to actually walk
    // the queue... which then destroys it for later use.
    // FIX: either skip this print, or print from a COPY
    // (queue<int> copy = org;) so the original stays intact.

    interleave2queues(org);

    for(int i=1; i<=10; i++){
        cout << org.front() << endl;
        org.pop();
        // Reminder: calling front() on an empty queue is undefined
        // behavior — always make sure the queue actually still has
        // elements before this kind of loop runs.
    }
}