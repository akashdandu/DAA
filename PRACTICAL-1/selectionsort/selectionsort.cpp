#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
    vector<int>selectionsort(vector<int>&nums){
    for(int i=0;i<nums.size();i++){
    int minindex=i;
    for(int j=i+1;j<nums.size();j++){
      if(nums[j]<nums[minindex]){
        minindex=j;
      }
    }
     swap(nums[i],nums[minindex]);
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
    selectionsort(nums);
    cout<<"sorted array: ";
    for(int val:nums){
        cout<<val<<" ";
    }
}   