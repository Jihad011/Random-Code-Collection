#include<stdio.h>
int main(){
int n,i;
scanf("%d",&n);
for(i=n;i>=1;i--)
printf("%d\t",i);
if(i%10==0)
printf("\n");
return 0;
}
