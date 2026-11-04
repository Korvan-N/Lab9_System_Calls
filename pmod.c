/**
 * korvan nameni
 * project: lab 9 system calls
 * class: CPE-2600 111
 */

// pmod.c
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    //reduce own priority by 10
    int nce = nice(10);
    printf("PID: %d\n", getpid());
    if(nce == -1){
        printf("failure to change nice.\n");
        exit(0);
    }
    //sleep for 1837272638 nanoseconds
    struct timespec time;
    time.tv_sec = 90;
    time.tv_nsec = 837272638;
    nanosleep(&time, NULL);

    printf("goodbye.\n");
    exit(0);

    return 0;
}