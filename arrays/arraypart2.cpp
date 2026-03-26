#include<iostream>
#include<climits>//for initialization if INT_MIN
using namespace std;
//subaaray code
void printsubarray(int *arr,int n){//n
    for(int start=0;start<n;start++){//n
        for(int end=start; end<n; end++){
            // cout<<"("<<start <<","<<end<<")";//start aur end ke ele aa gaye ab unke beech ke print karne hai
            for(int i=start;i<=end;i++){//n
                cout<<arr[i];
            }
            cout<<",";
        }
        cout<<endl;
    }
}
//max subarray code with brute force
void maxsubarraysum(int *arr1,int n1) {
    int maxSum= INT_MIN;//builtin fuction you can use if else logic also
    for( int start=0;start<n1;start++) {
        for(int end=start;end<n1;end++){
            int sumsubarray=0;
            for (int i=start;i<=end;i++){
                sumsubarray=sumsubarray+arr1[i];
            }
            cout<<sumsubarray<<",";
            maxSum=max(maxSum,sumsubarray);
        }
        cout<<endl;
    }
    cout<<"max subarray sum is"<<maxSum<<endl;
}
//optimizedsubarray
void maxsubarraysum2(int *arr1,int n1) {
    int maxSum= INT_MIN;//builtin fuction you can use if else logic also
    for( int start=0;start<n1;start++) {//start=2
        int sumsubarray=0;
        for(int end=start;end<n1;end++){//end=2,3,4,5
            sumsubarray=sumsubarray+arr1[end];//purane sum me hi add kar dege naye wale ending index ke element ko add karke
            cout<<sumsubarray<<",";
            maxSum=max(maxSum,sumsubarray);
        }
        cout<<endl;
    }
    cout<<"max subarray sum is"<<maxSum<<endl;
}
//kaden's method
void maxsubarraysum3(int *arr3,int n3) {
    int maxSum= INT_MIN;//builtin fuction you can use if else logic also
    int currsum=0;
    for(int i=0; i<n3;i++){
        currsum=currsum+arr3[i];
        maxSum=max(currsum,maxSum);
        if(currsum<0){
            currsum=0;
        }
    }
    cout<<maxSum<<endl;
}
//buy and sell stock
void maxprofit( int *prices,int n) {
    int bestbuy[1000];//as we can not do dynamic memory allocation in afunction like bestbuy[n] so max possible size
    bestbuy[0]=INT_MAX;
    cout<<bestbuy[0]<<",";
    for(int i=1;i<n;i++){//pehle hi ho chuka i=0
        bestbuy[i]=min(bestbuy[i-1],prices[i-1]);//main logic
        cout<<bestbuy[i]<<",";
    }
    int maxprofit=0;
    for(int i=0;i<n;i++){
        int currprofit=prices[i]-bestbuy[i];
        maxprofit=max(maxprofit,currprofit);
    }
    cout<<maxprofit<<endl;
    
}





int main(){
    //subarraystart
    int arr[5] ={1,2,3,4,5};
    int n=5;
    printsubarray(arr,n);
    //subarray end
    //maxsubarray brute force
    int arr1[6]={2,-3,6,-5,4,2};
    int n1=6;
    maxsubarraysum(arr1,n1);
    //optimized subarray
    maxsubarraysum2(arr1,n1);
    //kaden's rule
    maxsubarraysum3(arr1,n1);
    //buy and sell stocks
    int prices[6]={7,1,5,3,6,4};
    int n2=sizeof(prices)/sizeof(int);
    maxprofit( prices, n2);

    return 0;
}

