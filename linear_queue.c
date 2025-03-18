#include<stdio.h>
#define arr_size 5

void dequeue();
void enqueue();
void peek();
void display();

int front=0 , rear=-1 , data;
int arr[arr_size];

void main(){
	enqueue();
	enqueue();
	dequeue();
	peek();
	display();
}

void enqueue(){
	if(rear==arr_size-1){
		printf("\n Queue is full");
	}
	else{
		printf("Enter data: ");
		scanf("%d",&data);
		rear++;
		arr[rear]=data;
		printf("%d is enqueued \n ",arr[rear]);
	}
}

void dequeue(){
	if(front>rear){
		printf("\n Queue is empty");
	}
	else{
		int dequeuedata=arr[front];
		front++;
		printf("%d is dequeued \n",dequeuedata);
	}
}

void peek(){
	if(front>rear){
		printf("\n Queue is empty");
	}
	else{
		printf("%d is peeked \n",arr[front]);
	}
}

void display(){
	int i;
	if(front>rear){
		printf("\n Queue is empty");
	}
	else{
		printf("Displaying Queue: \n");
		for(i=front;i<=rear;i++){
			printf("%d",arr[i]);
		}
	}
}
