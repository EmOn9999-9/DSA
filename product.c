#include<stdio.h>

int product(int a, int b){
	if(b==0||a==0){
		return 0;
	}
	else{
		return a+product(a,b-1);
	}
}
int main(){
	int x,y;
	printf("enter two numbers ");
	scanf("%d%d",&x,&y);
	printf("Product is %d",product(x,y));
}
