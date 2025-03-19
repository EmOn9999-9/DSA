#include<stdio.h>
void heapify(int arr[], int n, int i){
	int largest,left,right;
	int temp;
	largest=i;
	left=2*i+1;
	right=2*i+2;
	if(left<n && arr[left]>arr[largest]){
		largest=left;
	}
	if(right<n && arr[right]>arr[largest]){
		largest=right;
	}
	if(largest!=i){
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heapify(arr,n,largest);
	}
}

void heapsort(int arr[],int n){
	int i,temp;
	for(i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(i=n-1;i>0;i--){
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heapify(arr,i,0);
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
	printf("Enter number of elements ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements: \n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Original array: \n");
	printArray(arr,n);
	heapsort(arr,n);
	printf("Sorted array: \n");
	printArray(arr,n);
	return 0;
}
