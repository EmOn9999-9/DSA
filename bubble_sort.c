#include<stdio.h>

void bubblesort(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		int swapped=0;
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapped=1;
			}
			if(swapped==1){
				break;
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
	bubblesort(arr,n);
	printf("Sorted array: \n");
	printArray(arr,n);
	return 0;
}
