#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{

    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    
    struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    
    // wait
    usleep(thread_func_args->wait_to_obtain_ms*1000);
    
    //obtain mutex
    pthread_mutex_lock(thread_func_args->mutex);
    
    //wait
    usleep(thread_func_args->wait_to_release_ms*1000);
    
    //release mutex
    pthread_mutex_unlock(thread_func_args->mutex);
    
    return thread_param;
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{
    /**
     * TODO: allocate memory for thread_data, setup mutex and wait arguments, pass thread_data to created thread
     * using threadfunc() as entry point.
     *
     * return true if successful.
     *
     * See implementation details in threading.h file comment block
     */
     
     //allocate memory
     struct thread_data* thread_param = malloc(sizeof *thread_param);
     
     //setup
     thread_param->mutex = mutex;
     //wait
     thread_param->wait_to_obtain_ms = wait_to_obtain_ms;
     //release
     thread_param->wait_to_release_ms = wait_to_release_ms;
     
     //pthread_create return value
     int rc = pthread_create(thread, NULL, threadfunc, (void*) thread_param);
     
     //check return value & return true if thread created successfully
     if (rc == 0){
         thread_param->thread_complete_success = true;
         return thread_param->thread_complete_success;
     }
     
     
    return false;
}

