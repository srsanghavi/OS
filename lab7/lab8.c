#include<stdio.h>
#include<stdlib.h>
int best(int blockSize);
int worst(int blockSize);
int first(int blockSize);
int next(int blockSize);
void dispayMemoryAllocation();


int memory[4][2] = {{0,1},{1,1},{3,1},{6,1}};
int last;

int main(){
	dispayMemoryAllocation();
	int sizeOfRequiredBlock,opt;
	
	while(1){
		printf("\nSelect the memory allocation scheme:\n1. First Fit\n2. Best Fit\n3. Next Fit\n4. Worst Fit\n5. Release Memory block\n6. End the program\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\n-------------------First Fit-----------------------\n");
				printf("\nEnter the memory block size: ");
				scanf("%d",&sizeOfRequiredBlock);
				if(first(sizeOfRequiredBlock))
					printf("\nMemory block allocated successfully!");
				else
					printf("\nMemory block cannot be allocated successfully!");
				dispayMemoryAllocation();
			break;
			case 2:
				printf("\n-------------------Best Fit-----------------------\n");
				printf("\nEnter the memory block size: ");
				scanf("%d",&sizeOfRequiredBlock);
				if(best(sizeOfRequiredBlock))
					printf("\nMemory block allocated successfully!");
				else
					printf("\nMemory block cannot be allocated successfully!");
				dispayMemoryAllocation();
			break;
			case 3:
				printf("\n-------------------Next Fit-----------------------\n");
				printf("\nEnter the memory block size: ");
				scanf("%d",&sizeOfRequiredBlock);
				if(next(sizeOfRequiredBlock))
					printf("\nMemory block allocated successfully!");
				else
					printf("\nMemory block cannot be allocated successfully!");
				dispayMemoryAllocation();
			break;
			case 4:
				printf("\n-------------------Worst Fit-----------------------\n");
				printf("\nEnter the memory block size: ");
				scanf("%d",&sizeOfRequiredBlock);
				if(worst(sizeOfRequiredBlock))
					printf("\nMemory block allocated successfully!");
				else
					printf("\nMemory block cannot be allocated successfully!");
				dispayMemoryAllocation();
			break;
			case 5:
				printf("\n----------------release some memory---------------\n");
				printf("\nEnter the block size(KBs) which you want to release(100, 200, 300, 400): ");
				scanf("%d",&sizeOfRequiredBlock);
				switch(sizeOfRequiredBlock){
					case 100:
						memory[0][1]=1;
						break;
					case 200:
						memory[1][1]=1;
						break;
					case 300:
						memory[2][1]=1;
						break;
					case 400:
						memory[3][1]=1;
						break;
					default:
						printf("\nEnter valid block size (100, 200, 300, 400): ");
				}
				dispayMemoryAllocation();
			break;
			case 6:
				return 0;
			break;
			
		}
	
	}
}
int best(int blockSize){
	int j;
	int flag=0;
	if(blockSize>0 && blockSize<=100){
		j=0;
	}
	else if(blockSize>100 && blockSize<=200){
		j=1;
	}
	else if(blockSize>200 && blockSize<=300){
		j=2;
	}
	else if(blockSize>300 && blockSize<=400){
		j=3;
	}
	else{
		printf("\nNo memory block available for input memory. ");
		return 0;
	}
	while(j!=4){
		if(memory[j][1]==1 && ((j+1)*100>=blockSize)){
			memory[j][1]=0;
			flag=1;			
			//index for next fit
			last=j;
			break;
		}
		j++;
	}
	if(flag==1)
		return 1;
	else 
		return 0;
}

int worst(int blockSize){
	int j=3,flag=0;
	if(blockSize<0 || blockSize>400){
		printf("\nNo memory block available for input memory.");
		return 0;
	}
	while(j>=0){
		printf("%d",memory[j][1]);
		if(memory[j][1]==1 && ((j+1)*100>=blockSize)){
			memory[j][1]=0;
			flag=1;			
			//index for next fit
			last=j;
			break;
		}
		j--;
	}
	if(flag==1)
		return 1;
	else 
		return 0;
}

int first(int blockSize){
	int j=0,flag=0;
	if(blockSize<0 || blockSize>400){
		printf("\nNo memory block available for input memory. ");
		return 0;
	}
	while(j!=4){
		if(memory[j][1]==1 && ((j+1)*100>=blockSize)){
			memory[j][1]=0;
			flag=1;			
			//index for next fit			
			last=j;
			break;
		}
		j++;
	}	
	if(flag==1)
		return 1;	
	else 
		return 0;
}

int next(int blockSize){
	int j=last+1, i=4, flag=0;
	if(blockSize<0 || blockSize>400){
		printf("\nNo memory block available for input memory.");
		return 0;
	}
	while(i){
		if((memory[j%4][1]==1) && (((j%4)+1)*100>=blockSize)){
			memory[j%4][1]=0;
			flag=1;			
			//index for next fit
			last=j;
			break;
		}
		j++;
		i--;
	}
	if(flag==1)
		return 1;
	else 
		return 0;	
}

void dispayMemoryAllocation(){
	int i;
	//Display the dispayMemoryAllocation scenario
	for(i=0;i<4;i++){		
		if(memory[i][1])
			printf("\n %dKB - available",(i+1)*100);
		else
			printf("\n %dKB - unavailable",(i+1)*100);
	}
}


