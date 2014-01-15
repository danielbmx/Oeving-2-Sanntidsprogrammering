# include <stdio.h>
# include <pthread.h>


int i = 0;


pthread_mutex_t lock; 


void* incrementor(){
    for(int x = 0; x < 1000000; x++){
        pthread_mutex_lock(&lock);
        i++;
        pthread_mutex_unlock(&lock);

    }
    return NULL;
}

void* decrementor(){
    for(int x = 0; x < 1000000; x++){
        pthread_mutex_lock(&lock);
        i--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(){

    pthread_mutex_init(&lock, NULL);

    // Thread 1:
    pthread_t thread1;
    pthread_create(&thread1, NULL, incrementor, NULL);
    
   
    // Thread 2:
    pthread_t thread2;
    pthread_create(&thread2, NULL, decrementor, NULL);
    
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL); 

    
    printf("Done: %i\n", i);
    return 0;
    
};


