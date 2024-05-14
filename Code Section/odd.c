#include<stdio.h>
int main(){
int n,i,ar[n];
scanf("%d",&n);
int t;
scanf("%d",&t);
int even=0,odd=0;
while(t--);
for(i=1;i<=n;i++){
scanf("%d",&ar[i]);
}
if(ar[i]%2!=0){
odd++;
}
if(ar[i]%2==0){
even++;
}
if(even>odd){
printf("Even");
}
else if(odd>even){
printf("Odd");
}
else{
printf("Draw");
}
return 0;
}
