#include <iostream>
#include <vector>
using namespace std;
/*Question1:ApplyMergesorttosortanarrayofStrings.(AssumethatallthecharactersinalltheStringsareinlowercase).(EASY)SampleInput1:arr={"sun","earth","mars","mercury"}SampleOutput1:arr={"earth","mars","mercury","sun"}*/
void merge(string arr[],int si,int mid,int ei){
    vector <string> temp;
    int i=si;
    int j=mid+1;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }

    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }
    for(int i=si;i<=ei;i++){
        arr[i]=temp[i-si];
    }

    

}
void mergesort(string arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=si+((ei-si)/2);
    mergesort(arr,si,mid);
    mergesort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
}
void print(string arr[],int n){
    for(int i=0;i<n;i++) {
        cout<<arr[i];
    }
    cout<<endl;
}
/*Question2:Givenanarraynumsofsizen,returnthemajorityelement.(MEDIUM)Themajorityelementistheelementthatappearsmorethan⌊n/2⌋times.Youmayassumethatthemajorityelementalwaysexistsinthearray.SampleInput1:nums=[3,2,3]SampleOutput1:3SampleInput2:nums=[2,2,1,1,1,2,2]SampleOutput2:2*/
int majorityelement(int arr[],int n) {
    int element;
    int count;
    for(int i=0;i<n;i++){
        element=arr[i];
        count=0;
        for(int j=0;j< n;j++){
            if(arr[j]==element){
                count++;
            }
        }
        if(count>n/2){
            return element;

        }
    }
    return -1;
}
/*Divide&Conquer(AssignmentQuestions)Question1:ApplyMergesorttosortanarrayofStrings.(AssumethatallthecharactersinalltheStringsareinlowercase).(EASY)SampleInput1:arr={"sun","earth","mars","mercury"}SampleOutput1:arr={"earth","mars","mercury","sun"}Question2:Givenanarraynumsofsizen,returnthemajorityelement.(MEDIUM)Themajorityelementistheelementthatappearsmorethan⌊n/2⌋times.Youmayassumethatthemajorityelementalwaysexistsinthearray.SampleInput1:nums=[3,2,3]SampleOutput1:3SampleInput2:nums=[2,2,1,1,1,2,2]SampleOutput2:2Constraints(extraConditions):●n==nums.length●1<=n<=5*104●-109<=nums[i]<=109Question3:Givenanarrayofintegers.FindtheInversionCountinthearray.(HARD)InversionCount:Foranarray,inversioncountindicateshowfar(orclose)thearrayisfrombeingsorted.Ifthearrayisalreadysortedthentheinversioncountis0.Ifanarrayissortedinthereverseorderthentheinversioncountisthemaximum.Formally,twoelementsa[i]anda[j]formaninversionifa[i]>a[j]andi<j.SampleInput1:N=5,arr[]={2,4,1,3,5}SampleOutput1:3,becauseithas3inversions-(2,1),(4,1),(4,3).swatirathore3522@gmail.com
SampleInput2:N=5,arr[]={2,3,4,5,6}SampleOutput2:0,becausethearrayisalreadysortedSampleInput3:N=3,arr[]={5,5,5}SampleOutput3:0,becausealltheelementsofthearrayarethesame&alreadyinasortedmanner.(Hint:Asortingalgorithmwillbeusedtosolvethisquestion.)Note-Thisquestionisimportant.Evenifyouarenotabletocomeupwiththeapproach,pleaseunderstandthesolution. */
//brute force
int inversioncount(int arr[],int n){
    int count=0;
    for ( int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            
            if(arr[i]>arr[j]){
                count++;
            }
            
        }
        
    }
    return count;
    

}
//mergesort
int merge(int arr[], int si,int mid,int ei){//time complexity O(n) and space complexity O(n)
    vector<int> temp;//temporary array
    int i=si;//iterator for left half
    int j=mid+1;//iterator for right half
    int count=0;
    

    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            count += (mid-i+1);  // all elements from i to mid are inversions
            temp.push_back(arr[j++]);
        }
    }
    //if left half is remaining
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    //if right half is remaining
    while(j<=ei){
        temp.push_back(arr[j++]);
    }
    //copy temp array to original array,loop original arrar par chll raha
    for(int i=si;i<=ei;i++){
        arr[i]=temp[i-si];
    }
    return count;
}
int mergesort(int arr[], int si,int ei){//time complexity O(logn) 
    //base case
    if(si>=ei){
        return 0;
    }
    int mid =(si +ei)/2;//si+(ei-si)/2 kyu nahi likha kyuki overflow ka chance nahi hai
    int count=0;
    count +=mergesort(arr,si,mid);//left half
    count +=mergesort(arr,mid+1,ei);//right half
    count +=merge(arr,si,mid,ei);//conquer step
    return count;
}
void printarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    string arr[4]={"sun","earth","mars","mercury"};
    string arr1[4]={"earth","mars","mercury","sun"};
    mergesort(arr,0,3);
    print(arr,4);
    mergesort(arr1,0,3);
    print(arr1,4);
    int nums[3]={3,2,3};
    cout<<majorityelement(nums,3);
    int nums1[7]={2,2,1,1,1,2,2};
    cout<<majorityelement(nums1,7);
    int arr2[5]={2,4,1,3,5};
    cout<<inversioncount(arr2,5);
    cout<<mergesort(arr2, 0,4);
    int arr3[5]={2,3,4,5,6};
    cout<<inversioncount(arr3,5);
    cout<<mergesort(arr3, 0,4);
    int arr4[3]={5,5,5};
    cout<<inversioncount(arr4,3);
    cout<<mergesort(arr4, 0,2);
    

}