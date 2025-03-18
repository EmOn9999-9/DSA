#include<stdio.h>

int num;
int pow(int p){
	if(p==1){
		return num;
	}
	else{
		return num*pow(p-1);
	}
}
int main(){
	int p;
	printf("enter a number ");
	scanf("%d",&num);
	printf("enter power ");
	scanf("%d",&p);
	printf("\n the answer is %d",pow(p));
}
