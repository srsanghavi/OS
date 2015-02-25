##author Shashwat Sanghavi

import time
from threading import *
import threading
from random import *

## In Python locks are used to achieve synchronization which are essential in order to implement monitor.
## It works same as sychronized class of java.
## above statements can be varified from http://effbot.org/zone/thread-synchronization.htm
##                                       http://stackoverflow.com/questions/8127648/how-to-synchronize-threads-in-python
##                                       http://www.laurentluce.com/posts/python-threads-synchronization-locks-rlocks-semaphores-conditions-events-and-queues/





lock = threading.Lock()                     ## this lock looks after whether store is full or not
lock1= threading.Lock()                     ## this lock looks after whether store is empty or not
l= threading.Lock()                         ## this lock allows producer to produce only one item at a time
l1= threading.Lock()                        ## this lock allows only one customer at a time

s=[]

def producer():
    global s
    time.sleep(randint(0,6))                
    if len(s) == 5:                         ## if queue is full it acquires a lock over thread which prevents producer to produce more items until customer bus something 
        print "\n<----items in store is"+str(len(s))+"---->"
        print "\n store is full, producer goes to sleep....."
        lock.acquire()
    l.acquire()
    lock.acquire()
    s.append(randint(0,10))
    lock.release()
    print "\n producer produced "+str(s[-1])
    if lock1.locked():
        lock1.release()
    l.release()


    
def consumer():
    global s
    time.sleep(randint(0,10))
    l1.acquire()
    if len(s) < 1:                  ##if queue is empty it acquires a lock over thread which prevents customer to buy more items until the producer produces more
        print "\n<----items in store is "+str(len(s))+"---->"
        print "\n consumer is waiting......."
        lock1.acquire()
    lock1.acquire()
    print "\n consumer consumed "+str(s[-1])
    del s[-1]
    if lock1.locked():
        lock1.release()
    if lock.locked():
        lock.release()
    l1.release()


for i in xrange(25):
    Thread(target=producer).start();
for j in xrange(5):
    Thread(target=consumer).start();

for i in xrange(15):
    Thread(target=producer).start();
for j in xrange(35):
    Thread(target=consumer).start();
