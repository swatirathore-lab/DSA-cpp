#include <iostream>
#include <Queue>
#include <stdlib.h>
#include <string>
using namespace std;
void firstnonrepeatingletter(string str){
    int freq[200] ={0};
    queue <char> q;
    for(int i=0;i<str.length();i++){
        int ch=str[i];
        freq[ch-'a']++;
        q.push(ch);
    }
    while(!q.empty() &&  freq[q.front()]>1){
        q.pop();
    }
    if(q.empty()){
        cout<<-1<<endl;
    }
    else{
        cout<<q.front()<<endl;
    }



    

}
int main(){
    string str="aabccxb";
    firstnonrepeatingletter(str);
    return 0;
}