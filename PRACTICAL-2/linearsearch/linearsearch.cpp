#include<bits/stdc++.h>
using namespace std;

int linearsearch(vector<int>&nums, int target){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int size;
    cout<<"size of the array:";
    cin>>size;
    vector<int>nums(size);
    for(int i=0;i<size;i++){
        cout<<"enter elements "<<i+1<<":";
        cin>>nums[i];
    }
    int target;
    cout<<"enter target element:";
    cin>>target;
    int result=linearsearch(nums,target);
    if(result==-1){
        cout<<"target not found";
    }
    else{
        cout<<"target found at index :"<<result;
    }
    
 };
