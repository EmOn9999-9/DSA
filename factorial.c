#include<stdio.h>

int fact(int num){
	if(num==0 || num==1){
		return 1;
	}
	else{
		return num*fact(num-1);
	}
}
int main(){
	int num;
	printf("enter a number ");
	scanf("%d",&num);
	printf("\n the factorial is %d",fact(num));
}
