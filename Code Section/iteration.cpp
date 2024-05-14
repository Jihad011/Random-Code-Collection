#include<bits/stdc++.h>
using namespace std;
int  main(){
int p,q,r=0;
cin>>p>>q;
for(int i=0;i<10;i++){
r+=p*i + q*i;
}
cout<<r<<endl;
}
