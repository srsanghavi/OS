import time
from threading import *
import threading

lock = threading.Lock() # lock required for one multiplication
lock1= threading.Lock() #lock required for another multiplication
global s1
global s2
global total
s1=0
s2=0
total=0
def multiply(x,y):
    lock.acquire();
    time.sleep(2)
    global s1
    s1=x*y;
    lock.release()


def multiply1(x,y):
    lock1.acquire();
    global s2
    s2=x*y;
    lock1.release();

def sumx(x,y):
    lock.acquire()  #if both multiplication are done and their locks are free then and then only sum procedure will be carried forward.
    lock1.acquire()
    global total
    total=s1+s2
    lock.release()
    lock1.release()
    print s1,s2,total



Thread(target=multiply,args=([3,2])).start();
Thread(target=multiply1,args=([4,3])).start();
Thread(target=sumx,args=(s1,s2)).start();

