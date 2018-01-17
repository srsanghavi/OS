/*
first in first out process scheduler simulation.

Author: Shashwat Sanghavi
*/
#include<stdio.h>
#include<stdlib.h>

struct queue{	//queue datastucture for handling the queue of processes
	int id,burstTime;
	struct queue *next;
} *head=NULL,*curr;
int tatp=0;
 
void enqueue(int id,int burstTime){
	struct queue *temp;
	temp=malloc(sizeof(struct queue));
	temp->id=id;
	temp->burstTime=burstTime;
	temp->next=NULL;
	
	if(head==NULL){
		head=temp;
		curr=head;
	}
	else{
		curr->next=temp;
		curr=curr->next;
		
	}	
}

int dequeue(){
	int id;
	if(head==NULL){
		printf("all processes are done");
		return -1;		
	}
	else{
		id=head->id;
		printf("\nwaiting time for process %d is: %d",head->id,tatp);
		tatp=tatp+head->burstTime;
		printf("\nturn around time for process %d is: %d\n",head->id,tatp);
		head=head->next;
		return 0;
		
	}
}

int main(){
	int numberOfProcess,burstTime,itr;
	printf("\nenter number of process:");
	scanf("%d",&numberOfProcess);
	printf("\nEnter burst time for each processes:\n");
	for(itr=0;itr<numberOfProcess;itr++){	//taking all proccesses
		scanf("%d",&burstTime);
		enqueue(itr+1,burstTime);
	}
	
	for(itr=0;itr<numberOfProcess;itr++){	//executing processes
		dequeue();
	}



}
