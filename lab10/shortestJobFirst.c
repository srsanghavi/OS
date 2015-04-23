#include<stdio.h>
#include<stdlib.h>
struct ptask{
	int btime;
	int pid;
};
int main(){
	int numberOfProcess,itr,itr1,btimeTemp,waiting=0,pidTemp;
	struct ptask *task;
	printf("enter total number of process:");
	scanf("%d",&numberOfProcess);
	task=malloc(numberOfProcess*sizeof(struct ptask));
	itr=0;
	while(itr<numberOfProcess){
		task[itr].pid=itr+1;
		scanf("%d",&task[itr].btime);
		itr++;
	}
	for(itr=0;itr<numberOfProcess-1;itr++){
		for(itr1=itr+1;itr1<numberOfProcess;itr1++){\
			if(task[itr].btime>task[itr1].btime){
				btimeTemp=task[itr].btime;
				pidTemp=task[itr].pid;
				task[itr].btime=task[itr1].btime;
				task[itr].pid=task[itr1].pid;
				task[itr1].btime=btimeTemp;
				task[itr1].pid=pidTemp;
			}
		}
	}
	for(itr=0;itr<numberOfProcess;itr++){
		printf("process %d-waiting time %d-turn around time %d\n",task[itr].pid,waiting,waiting+task[itr].btime);
		waiting=waiting+task[itr].btime;
	}
}
