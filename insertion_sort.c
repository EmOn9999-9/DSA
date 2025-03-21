#include<stdio.h>

void insertionsort(int arr[],int n){
	int i,j,key;
	for(i=0;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void printArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	int i,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements: \n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Original array: \n");
	printArray(arr,n);
	insertionsort(arr,n);
	printf("Sorted array: \n");
	printArray(arr,n);
	return 0;
}
