#include<stdio.h>
int main(){
int t;
scanf("%d",&t);
while(t--){
int a,b;
scanf("%d%d ",&a,&b);
if(a>b)
printf("%d%d",a,b);
else printf("%d%d ",b,a);
}
return 0;
}
