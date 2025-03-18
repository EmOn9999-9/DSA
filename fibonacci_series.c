#include<stdio.h>

int fib(int num)
{
	if(num==1){
		return 0;
	}
	else if(num==2){
		return 1;
	}
	else{
		return fib(num-1)+fib(num-2);
	}
}
int main()
{
	int i,n;
	printf("\n Enter no. of elements");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("%d ",fib(i));
	}
}
