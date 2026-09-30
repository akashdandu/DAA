#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int fact =1;
    for(int i=1;  i<=n; i++){
        fact *= i;
    }
    return fact;
}
int main(){
    int n;
    cout<<"enter the number to find factorial : ";
    cin>>n;
    cout<<"factorial of "<<n<<" is :"<<factorial(n);
    return 0;
}
