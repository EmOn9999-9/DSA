#include<stdio.h>
void merge(int arr[], int left, int mid,int right){
	int n1=mid-left+1;
	int n2=right-mid;
	int L[n1],R[n2],i,j,k;
	for(i=0;i<n1;i++){
		L[i]=arr[left+i];
	}
	for(j=0;j<n2;j++){
		R[j]=arr[mid+1+j];
	}
	i=0;
	j=0;
	k=left;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}
}

void mergesort(int arr[],int left,int right){
	int mid;
	if(left<right){
		mid=left+(right-left)/2;
		mergesort(arr,left,right);
		mergesort(arr,mid+1,right);
		merge(arr,left,mid,right);
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
	mergesort(arr,0,n-1);
	printf("Sorted array: \n");
	printArray(arr,n);
	return 0;
}
