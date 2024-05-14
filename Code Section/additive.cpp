#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int a,b,n;
cout<<"Take the range"<<endl;
cin>>n;
cout<<"Pleasse enter a value of a"<<endl;
cin>>a;
cout<<"The additive inverse of "<<a<<" is:"<<endl;
if(a==0){
cout<<"0"<<endl;
}
b=n-a;
//10-1=9;
cout<<b<<endl;
if((a+b)%n==0){
cout<<"Checking complete"<<endl;

}
}

}
