// TODO: add the appropriate head files here
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "lab2.h"

/************************************************************\
 * get_arguments - returns the command line arguments not
 *                 including this file in an array with the
 *                 last element as null.  This is the format
 *                 that the execvp() function requires.
 * 
 * For example:  ./time ls -l
 * will return an array consisting of {"ls","-l", NULL}
 ************************************************************/
char** get_arguments(int argc, char** argv){
    int arg_length = argc;
    char**  cmd_args = NULL;

    if (arg_length > 0){
        cmd_args = (char**)malloc(sizeof(char*)*arg_length);
    }
    for(int i = 0; i < arg_length-1; i++){
        cmd_args[i] = argv[i+1];
    }
    cmd_args[arg_length-1] = NULL;
    return cmd_args;
}
char *ipc_create(int);
void ipc_close();
double elapsed_time();


int main(int argc, char** argv)
{
    pid_t pid;
    int status;
    char* command = NULL;
    char** command_args = NULL;
    char* ipc_ptr = NULL; // pointer to shared memory
    struct timeval start_time;
    struct timeval current_time;
    int fd;
    const char *name = "lab2";
    char *ptr;
    const int SIZE = 16384;
    struct timeval time;


    if (argc < 2){
        fprintf(stderr,"SYNOPSIS: %s <cmd> <cmd arguments>\n",argv[0]);
        return 1;
    }
    
    // TODO: call ipc_create to create shared memory region to which parent
    //       child have access.
        ipc_ptr = ipc_create(SIZE);
    }
    pid = fork();

    if (pid < 0)
    { /* error occurred */
        fprintf(stderr, "Fork failed!");
        return 2;
    }
    else if (pid == 0)
    { /*child process */
        // TODO: use gettimeofday to log the start time
        gettimeofday(&time, NULL);

        // TODO: write the time to the IPC
        memcpy(ipc_ptr, &time, sizeof(time));

        // TODO: get the list of arguments to be used in execvp() and
        // execute execvp()
        command_args = get_arguments(argc, argv);
        execvp(command_args[0], command_args);
    }




        // TODO: write the time to the IPC
          int fd = shm_open("lab2",O_CREAT | O_RDWR,0666);
        if (fd == -1);
        perror("shm_open");
        return NULL;
        
        if(ftruncate(fd, size)== -1){
        perror("ftruncate");
        close(fd);
        return NULL;
    }
        char* ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if (ptr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return NULL;    


        
        // TODO: get the list of arguments to be used in execvp() and 
        // execute execvp()
        int main() {
            // Define the command line and arguments 
            char *args[] = {"ls","-l",NULL};
            // Execute the command 
            execvp(args[0],args)
            // if execvp returns then that means it failed 
            perror("execvp failed");
        }

    }
    else { /* parent process */
        // TODO: have parent wait and get status of child.
        //       Use the variable status to store status of child. 
            pid =  wait(NULL);
        // TODO: get the current time using gettimeofday
        gettimeofday(&current_time,NULL);
        // TODO: read the start time from IPC
        memcpy(&start_time,ipc_ptr,sizeof(ipc_ptr));
        // TODO: close IPC
        ipc_close;

        // NOTE: DO NOT ALTER THE LINE BELOW.
        printf("Elapsed time %.5f\n",elapsed_time(&start_time, &current_time));
    
    return status;
}