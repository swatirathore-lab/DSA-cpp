#include <iostream>
#include <string>//for using string class
#include <cstring>//for using string functions like strcpy, strcat, strcmp  
using namespace std;
void toUpper(char word[],int n){
    for(int i=0;i<n;i++){
        int ch=word[i];
        if(ch>='A'&& ch<='Z'){
            continue;

        }
        else {
            word[i]=ch-'a'+'A';
        }

    }

}
void reverse(char word[],int n){
    int start=0,end=n-1;
    while(start<=end){
        // swap(word[start],word[end]);
        // start++;
        // end--;
        swap(word[start++],word[end--]);
    }
}
bool palindrom(char word[],int n){
    int start=0,end=n-1;
    while(start<end){
        if(word[start++]!=word[end--]){
            return false;
        }
    }
    cout<<"valid palindrome\n"<<endl;
    return true;
}
void specialstringfunctions(){
    char str[100];
    //str[100]="apna college"; // this is not valid because we cannot assign a string to a char array after declaration
    strcpy(str,"apna college"); // this is valid because we can copy a string to
    char str1[]="Hello";
    char str2[]="World";
    char str3[20];
    // copy str1 to str3
    strcpy(str3,str1);
    cout<<str3<<endl;
    // concatenate str1 and str2 and store in str3
    strcat(str3,str2);
    cout<<str3<<endl;
    // compare str1 and str2
    if(strcmp(str1,str2)==0){
        cout<<"str1 and str2 are equal\n"<<endl;
    }
    else {
        cout<<"str1 and str2 are not equal\n"<<endl;
    }
}
void cplusplusstring() {
    string str;
    cin>> str;
    cout << str<< endl;// jha par bhi whitespace aaygi wha input band to phir
    string str;
    getline(cin,str);// this will take input until the user presses enter key   
    cout << str<< endl;

}
void foreachloop(){
    string str="Hello World";
    for(int i=0;i<str.length();i++){
        cout<<str[i]<<" ";// for normal index values
    }
    cout<<endl;
    for(char ch:str){
        cout<<ch<<" ";//for getting each character in the string without using index values
    }
    cout<<endl;
}
void stringsmemeberfunctions(){
    string str="Hello World";
    cout<<str.length()<<endl;// for getting the length of the string
    cout<<str.size()<<endl;// for getting the size of the string
    cout<<str.empty()<<endl;// for checking if the string is empty or not
    cout<<str.substr(0,5)<<endl;// for getting a substring from the string
    cout<<str.find("World")<<endl;// for finding the index of a substring in the string
    cout<<str.replace(0,5,"Hi")<<endl;// for replacing a substring in the string
    cout<<str.at(3)<<endl;// for getting the character at a specific index in the string
}
bool validanagram(string str1,string str2){
    if(str1.length()!=str2.length()){
        cout<<"Not an anagram\n"<<endl;
        return false;
    }
    int count[26]={0};
    for(int i=0;i<str1.length();i++){
        int idx = str1[i]-'a';
        count[idx]++;
    }
    for (int i=0;i<str2.length();i++){
        int idx = str2[i]-'a';
        if(count[idx]==0){
            cout<<"Not an anagram\n"<<endl;
            return false;
        }
        count[idx]--;
    }
    cout<<"Valid anagram\n"<<endl;
    return true;   
}
void oprusagewithstrings(){
    string str1="Hello";
    string str2="World";
    string str3=str1+str2;// for concatenating two strings
    cout<<str3<<endl;
    if(str1==str2){
        cout<<"str1 and str2 are equal\n"<<endl;
    }
    else {
        cout<<"str1 and str2 are not equal\n"<<endl;
    }
}
int main() {
    char word[]="ApPle";
    toUpper(word,strlen(word));
    cout<<word<<endl;
    reverse(word,strlen(word));
    cout<<word<<endl;   
    char word2[]="madam";
    palindrom(word2,strlen(word2));
    return 0;
}
