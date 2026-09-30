#include<bits/stdc++.h>
using namespace std;
    vector<int>insertionsort(vector<int>&nums){
    for(int i=1;i<nums.size();i++){
    int curr=nums[i];
    int j=i-1;
    while(j>=0&&nums[j]>curr){
        nums[j+1]=nums[j];
        j--;
    }
    nums[j+1]=curr;
    }
    
  
  return nums;
};
int main(){
    int size;
    cout<<"size of the array:";
    cin>>size;
    vector<int>nums(size);
    for(int i=0;i<size;i++){
        cout<<"enter elements "<<i+1<<":";
        cin>>nums[i];
        
    }
    insertionsort(nums);
    cout<<"sorted array: ";
    for(int val:nums){
        cout<<val<<" ";
    }
}
