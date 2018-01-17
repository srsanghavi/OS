#include<stdio.h>
#include<stdlib.h>

struct task{
	int rtime,deadline,etime;
};
int main(){
	system("tabs -3");
	int t,itr,totalExec=0,**g,itr1,i,j,index,flag,slack;
	struct task *process;
	printf("enter the number of processes");
	scanf("%d",&t);
	process=malloc(sizeof(struct task)*t);
	for(itr=0;itr<t;itr++){
		printf("\nEnter realease time of process %d: ",itr);
		scanf("%d",&process[itr].rtime);
		printf("\nEnter deadline of process %d: ",itr);
		scanf("%d",&process[itr].deadline);
		printf("\nEnter execution time of process %d: ",itr);
		scanf("%d",&process[itr].etime);
		//totalExec=totalExec+process[itr].etime;
	}
	totalExec=40;
	g=malloc(sizeof(int *)*t);
	for(itr=0;itr<t;itr++){
		g[itr]=malloc(sizeof(int)*totalExec);	
	}
	for(itr=0;itr<t;itr++){
		for(itr1=0;itr1<totalExec;itr1++){
			g[itr][itr1]=(int)' ';
		}
				
	}
	printf("\n\n\t\t\t\tGantt Chart\nprocess\t");
	for(itr=0;itr<totalExec;itr++){
		printf("%d\t",itr);
		j=totalExec;
		flag=0;
		for(itr1=0;itr1<t;itr1++){
			slack=(process[itr1].deadline-itr)-process[itr1].etime;
			if(process[itr1].rtime<=itr && j>=slack && process[itr1].etime>0){
				i=process[itr1].rtime;
				j=slack;
				index=itr1;
				flag=1;
			}
			
		}
		if(flag==1){	
				g[index][itr]=(int)'1';
				process[index].etime--;
			}
				
	}
	for(itr=0;itr<t;itr++){
				printf("\n");
				printf("%d\t\t\t",itr);
		for(itr1=0;itr1<totalExec;itr1++){
			printf("%c\t",g[itr][itr1]);
		}

				
	}	
	printf("\n\n");	
}
