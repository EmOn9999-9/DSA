#include<stdio.h>

void selectionsort(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[i]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
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
	printf("Enter %d elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Original array: \n");
	printArray(arr,n);
	selectionsort(arr,n);
	printf("Sorted array: \n");
	printArray(arr,n);
	return 0;
}
