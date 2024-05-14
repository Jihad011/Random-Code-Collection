#include<bits/stdc++.h>
using namespace std;
int extended_euclid(int a,int b,int &x,int &y){
if(b==0){
x=1;
y=0;
return a;
}
int x1,y1;
int gcd=extended_euclid(b,a%b,x1,y1);
x=y1;
y=x1-floor(a/b)*y1;
return gcd;
}
int main()
{
//Our equation 8x+44y=52
int a=8,b=44,x_g,y_g,c=52;
int gcd=extended_euclid(a,b,x_g,y_g); //8x+44y=gcd(a,b) এর জন� সমাধান �বর
if(c%gcd!=0){// যিদ c, gcd �ারা িনঃেশেষ িবভাজ� না হয় তেব x,y এর �কান পূণ� মােনর
cout<<"The equation has no solution!\n";
return 0;
}
int k=3; // k এর মান ইে�মত ধের িনন।
int x=x_g*c/gcd+k*b/gcd;
int y=y_g*c/gcd-k*a/gcd;
cout<<"Solution for 8x+44y=52 is: x="<<x<<"; y="<<y<<endl;
return 0;
}
এখেন আমরা সবার �থেম Extended Euclidean Algorithm অন