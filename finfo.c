/**
 * korvan nameni
 * project: lab 9 system calls
 * class: CPE-2600 111
 */

// finfo.c
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void print_type(mode_t mode);
void print_perm(mode_t mode);
int main(int argc, char* argv[]){
    if(argc==2){
        struct stat hi;
        int error = stat(argv[1], &hi);
        if(error == -1){
            printf("choose a valid file.\n");
            exit(1);
        }
        printf("name is %s\n", argv[1]);
        
        //print file type
        print_type(hi.st_mode);

        //print permissions for user
        print_perm(hi.st_mode);

        //print file owner number
        printf("File owner: %d\n", hi.st_uid);

        //print file size in bytes
        double kb = hi.st_size/1000.0;
        printf("file size (bytes): %.02f kB\n", kb);

        //print last modified
        char time[100];
        struct tm *tme = localtime(&hi.st_mtim.tv_sec);
        strftime(time, sizeof(time), "%m-%d-%y %H:%M:%S", tme);
        printf("time of last modification: %s\n", time);
    }
    else{
        printf("input a file as an argument. input 1 argument exactly.\n");
    }

    return 0;
}
/**
 * print file type
 */
void print_type(mode_t mode){
    if(S_ISREG(mode)){
        puts("File Type: Regular File");
    }
    else if (S_ISDIR(mode)){
        puts("File Type: Directory");
    }
    else if (S_ISLNK(mode)){
        puts("File Type: Symbolic Link");
    }
    else if (S_ISCHR(mode)){
        puts("File Type: Character Device");
    }
    else if (S_ISBLK(mode)){
        puts("File Type: Block Device");
    }
    else if (S_ISFIFO(mode)){
        puts("File Type: FIFO/Pipe");
    }
    else if (S_ISSOCK(mode)){
        puts("File Type: Socket");
    }
    else{
        puts("File Type: Unknown");
    }
}
/**
 * print user permissions
 */
void print_perm(mode_t mode){
    int nul = 1;
    printf("User permissions: ");
    if(S_IRUSR & mode){
        printf("Read ");
        nul = 0;
    }
    if(S_IWUSR & mode){
        printf("Write ");
        nul = 0;
    }
    if(S_IXUSR & mode){
        printf("Execute");
        nul = 0;
    }
    if(nul){
        printf("None");
    }
    printf("\n");
}