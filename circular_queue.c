#include<stdio.h>
#define arr_size 5

void dequeue();
void enqueue();
void peek();
void display();

int front=-1 , rear=-1 , data;
int arr[arr_size];

void main(){
	enqueue();
	enqueue();
	enqueue();
	dequeue();
	peek();
	display();
}

void enqueue(){
	if(front==-1 && rear==-1){
		printf("Enter data: ");
		scanf("%d",&data);
		front=0;
		rear=0;
		arr[rear]=data;
		printf("%d is enqueued \n ",arr[rear]);
	}
	else if(front==(rear+1)%arr_size){
		printf("\n Queue is full");
	}
	else{
		printf("Enter data: ");
		scanf("%d",&data);
		rear=(rear+1)%arr_size;
		arr[rear]=data;
		printf("%d is enqueued \n ",arr[rear]);
	}
}

void dequeue(){
	if(front==-1){
		printf("\n Queue is empty");
	}
	else if(front==rear){
		int dequeuedata=arr[front];
		front=-1;
		rear=-1;
	}
	else{
		int dequeuedata=arr[front];
		front=(front+1)%arr_size;
		printf("%d is dequeued \n",dequeuedata);
	}
}

void peek(){
	if(front==-1){
		printf("\n Queue is empty");
	}
	else{
		printf("%d is peeked \n",arr[front]);
	}
}

void display(){
	int i;
	if(front==-1){
		printf("\n Queue is empty");
	}
	else{
		printf("Displaying Queue: \n");
		i=front;
		while(i!=rear){
			printf("%d \n",arr[i]);
			i=(i+1)%arr_size;
		}
		printf("%d \n",arr[rear]);
	}
}
