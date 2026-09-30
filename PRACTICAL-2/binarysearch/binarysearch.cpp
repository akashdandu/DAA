#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&nums, int target){
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
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
    int result=binarysearch(nums,target);
    if(result==-1){
        cout<<"target not found";
    }
    else{
        cout<<"target found at index :"<<result;
    }
}