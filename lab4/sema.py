import threading
import time
from random import randint
sema = threading.Semaphore(0)
msg = None

def producer():
    print "I'm the producer"
    print "Producer not available"
    time.sleep(randint(5,15))
    global msg
    msg = "hi! whats up"
    print "Producer available. Signaling the consumer."
    sema.release()

def consumer():
    print "consumer"
    print "Consumer is waiting."
    sema.acquire()
    print "Consumer got",msg

t1 = threading.Thread(target=producer)
t2 = threading.Thread(target=consumer)
t3 = threading.Thread(target=consumer)
t4 = threading.Thread(target=consumer)#will never get sem signal so will wait for infinite time
t5 = threading.Thread(target=producer)
t5.start()
t1.start()
t2.start()
time.sleep(5)

t3.start()
t4.start()
