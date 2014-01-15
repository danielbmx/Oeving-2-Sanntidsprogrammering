from threading import Thread, Lock


i = 0
lock = Lock()

def incrementor():
    global i
    for x in range(0, 1000000): 
        lock.acquire()    
        i += 1
        lock.release()
        
def decrementor():
    global i
    for x in range(0, 1000000):
        lock.acquire()     
        i -= 1
        lock.release()

        
def main():
    
    # Thread 1:
    adder_thr = Thread(target = incrementor)
    adder_thr.start()
    
    
    # Thread 2: 
    minus_thr = Thread(target = decrementor)
    minus_thr.start()
    
    adder_thr.join()
    minus_thr.join() 
    
    print("Done: " + str(i))
    
main()
