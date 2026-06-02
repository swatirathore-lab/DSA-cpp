#include<iostream>
using namespace std;
//tiling problem
int tp(int n){
    if(n==0 || n==1){
        return 1;
    }
    //vertical
    int ans1=tp(n-1);
    //horizontal
    int ans2=tp(n-2);
    return ans1+ans2;

}
//remove duplicates from a string
void removeDuplicates(string str,string ans,int i ,int map[26]){
    if(i==str.length()){
    cout<<ans<<endl;
    return;
    }
    char ch=str[i];
    int mapindex=(int) (ch-'a');
    if (map[mapindex]) {
        //duplicate
        removeDuplicates(str, ans, i + 1, map);
    } else {
        //not duplicate
        map[mapindex] = 1;
        removeDuplicates(str, ans+str[i], i + 1, map);
    }
} 
//remove duplicates from a string without i
void removeDuplicates1(string str,string ans,int map[26]){
    if(str.size()==0){
    cout<<ans<<endl;
    return;
    }
    int n=str.size();
    char ch=str[n-1];
    int mapindex=(int) (str[n-1]-'a');
    str=str.substr(0,n-1);
    if (map[mapindex]) {
        //duplicate
        removeDuplicates1(str, ans, map);
    } else {
        //not duplicate
        map[mapindex] = 1;
        removeDuplicates1(str, ans+ch, map);
    }
}
//friends [pairing problem
int friendspairing(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    //or return friendspairing(n-1)+ (n-1)*friendspairing(n-2);
    //single
    int ans1=friendspairing(n-1);
    //pair
    int ans2=(n-1)*friendspairing(n-2);
    return ans1+ans2;
}
//binary stringd
void binarystringd(int n,int lastplace,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(lastplace!='1'){
        binarystringd(n-1,0,ans+'0');
        binarystringd(n-1,1,ans+'1');
    }else{
        binarystringd(n-1,0,ans+'0');
    }
}
//binary string without using lastplace
void binarystringd1(int n,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(ans[ans.size()-1]!='1'){
        binarystringd1(n-1,ans+'0');
        binarystringd1(n-1,ans+'1');
    }else{
        binarystringd1(n-1,ans+'0');
    }
}
    


int main() {
    int n;
    cout << "Enter the number of tiles: ";
    cin >> n;
    cout << "Number of ways to tile the floor: " << tp(n) << endl;
    string str="hello";
    string ans="";
    int map[26]={false};
    removeDuplicates(str, ans, 0, map);
    int map1[26]={false};
    removeDuplicates1(str, ans, map1);
    int friends;
    cout<<"Enter the number of friends: "; 
    cin>>friends;
    cout<<"Number of ways to pair friends: "<<friendspairing(friends)<<endl;
    int n1;
    cout<<"Enter the length of binary string: ";
    cin>>n1;
    binarystringd(n1, 0, " ");
    binarystringd1(n1, " ");
    
    return 0;

}