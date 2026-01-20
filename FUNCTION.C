#include<stdio.h>
#include<conio.h>
void main()
{
int n,i;
printf("Enter the number of term");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("%d", fib(i));
}
}
int fib(int x)
{
if(x<0)
{
printf("fib is not possible");
}
else if (x==0)
{
return 0;
}
else
{
return fib(x-1)+fib(x-2);
}
}
























































































































