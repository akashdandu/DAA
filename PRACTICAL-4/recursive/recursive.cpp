#include<bits/stdc++.h>
using namespace std;

int recursivemethod(int n){
    if(n ==0||n==1){
        return 1;
    }
    else{
        return n*recursivemethod(n-1);
    }
}

int main(){
    int n;
    cout<< " enter the number to find factorial : ";
    cin>>n;
    cout<<"factorial of "<<n<<" is :"<<recursivemethod(n);
    return 0;
}