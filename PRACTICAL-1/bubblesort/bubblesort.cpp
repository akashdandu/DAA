#include<bits/stdc++.h>
using namespace std;
vector<int>bubblesort(vector<int>&nums){
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size()-i-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
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
   bubblesort(nums);
   cout<<"sorted array: ";
   for(int val:nums){
    cout<< val <<" ";
   }
   return 0;
}