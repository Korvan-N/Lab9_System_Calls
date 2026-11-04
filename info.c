/**
 * korvan nameni
 * project: lab 9 system calls
 * class: CPE-2600 111
 */

// info.c
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
int main(void){
    // print current time in nanoseconds
    struct timespec start;
    int tmp = clock_gettime(CLOCK_REALTIME, &start);
    if(tmp != -1){
        long tiempo = start.tv_sec%(60*60*24)*1E9+start.tv_nsec;
        printf("the current time in nanoseconds is %ld\n",tiempo);
    }
    

    // print network name
    char hostname[256];
    tmp = gethostname(hostname, sizeof(hostname));
    if(tmp != -1){
        printf("the network name is %s\n", hostname);
    }

    struct utsname unamedata;
    tmp = uname(&unamedata);
    if(tmp != -1){
        //print OS name
        printf("the operating system name is %s\n", unamedata.sysname);
        // print OS release
        printf("OS release: %s\n", unamedata.release);
        // print OS version
        printf("OS version: %s\n", unamedata.version);
        // print system hardware type
        printf("the system hardware type is %s\n", unamedata.machine);
    }
    

    // print number of CPUs
    int processors = get_nprocs();
    if(processors != -1){
        printf("%d CPUs\n", processors);
    }

    // print physical memory in bytes
    if(sysconf(_SC_PHYS_PAGES) != -1){
        long physical_mem = sysconf(_SC_PHYS_PAGES) * getpagesize();
        printf("total physical memory (bytes): %li\n", physical_mem);
    }

    // print free memory in bytes
    struct sysinfo infodata;
    sysinfo(&infodata);
    printf("free memory (bytes): %li\n", infodata.freeram*infodata.mem_unit);
    return 0;
}