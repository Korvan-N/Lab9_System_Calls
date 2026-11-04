/**
 * korvan nameni
 * project: lab 9 system calls
 * class: CPE-2600 111
 */

// pnfo.c
#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>
void print(pid_t pid);
int verify(char* input);
int main(int argc, char* argv[]){
    if(argc == 2){
        //print all the information if the input is valid
        if(verify(argv[1]) != -1){
            print(atoi(argv[1]));
        }
        else{
            printf("please enter a valid PID.\n");
        }
    }
    else if(argc == 1){
        //else if no arguments then use current process
        print(getpid());
    }
    else{
        printf("bad arguments.\n");
    }
    return 0;
}

/**
 * print pid, its priority, and its scheduling method
 */
void print(pid_t pid){
    if(getpriority(PRIO_PROCESS, pid) == -1){
        printf("invalid PID.\n");
        exit(0);
    }
    printf("pid is %d\n", pid);

    printf("priority: %d\n",getpriority(PRIO_PROCESS, pid));

    printf("scheduling method: ");
    switch (sched_getscheduler(pid)) {
        case SCHED_OTHER:
            puts("SCHED_OTHER");
            break;
        case SCHED_BATCH:
            puts("SCHED_BATCH");
            break;
        case SCHED_IDLE:
            puts("SCHED_IDLE");
            break;
        case SCHED_FIFO:
            puts("SCHED_FIFO");
            break;
        case SCHED_RR:
            puts("SCHED_RR");
            break;
        default:
            puts("Unknown policy");
            exit(0);
    }
}
/**
 * make sure input has integers only
 */
int verify(char* input){
    int i = 0;
    while(input[i] != '\0'){
        if(input[i]<48 || input[i] >57){
            return -1;
        }
        i++;
    }
    return 0;
    
}