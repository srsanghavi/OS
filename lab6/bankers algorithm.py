## Banker's algorithm
##
## Author: Shashwat Sanghavi
##
## This code is the implemenation of bankers algorithm for R resources and P processes.
## One needs to provide allocated resources to each proccesses, Max required processes
## For each process and total available resources at the point of time in order to detect
## whether there is any safe sequence or not.
##
## OutPut: 1) if there exists any safe sequence then this script will output one safe sequence.
##         2) if there is no safe sequence then this script will output that given scenario will lead to deadlock condition.



from random import *
import numpy as np
P=input("Enter number of processes");
R=input("Enter number of resources");

temp=[]
for i in xrange(R):
    temp.append(0)

AvailableResources=[]
allocated=[]
RequiredResources=[]


for i in xrange(R):
    x=input("Enter the available number resource"+str(i)+":");
    AvailableResources.append(x)

for i in xrange(P):
    RequiredResources.append([])
    for j in xrange(R):
        x=input("Enter the total number of "+str(i)+" resources required for process "+str(j)+":");
        RequiredResources[i].append(x)

for i in xrange(P):
    allocated.append([])
    for j in xrange(R):
        x=input("Enter the total number of "+str(i)+" resources allocated to process "+str(j)+":");
        allocated[i].append(x)


print "available resources are " + str(AvailableResources)
print "allocated Resources are " + str(allocated)
print "Required resources are " + str(RequiredResources)
flag=0
count=0
run=1


while(run==1):
    for i in xrange(P):
        if count>=P and run==1:
            for i in xrange(P):
                if(RequiredResources[i]==temp):
                    flag=0
                else:
                    flag=1
            if flag==1:
                print "DeadLock detected"
                run=0
            else:
                print "all proccesses done"
                run=0 

        if (list(np.subtract(AvailableResources,list(np.subtract(RequiredResources[i],allocated[i]))))>=temp and RequiredResources[i]>temp):
            print "process" +str(i)
            AvailableResources=np.add(allocated[i],AvailableResources)
            RequiredResources[i]=temp
            allocated[i]=temp
            count=0
        else:
            count=count+1
