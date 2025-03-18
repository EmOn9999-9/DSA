#include<stdio.h>

int sum(int n){
	if(n==1){
		return 1;
	}
	else{
		return n+sum(n-1);
	}
}
int main(){
	int n;
	printf("enter a number ");
	scanf("%d",&n);
	printf("Sum is %d",sum(n));
}
