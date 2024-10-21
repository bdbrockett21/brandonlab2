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
char** get_arguments(int argc, char** argv) {
    int arg_length = argc;
    char** cmd_args = NULL;

    if (arg_length > 0) {
        cmd_args = (char**)malloc(sizeof(char*) * arg_length);
    }
    for (int i = 0; i < arg_length - 1; i++) {
        cmd_args[i] = argv[i + 1];
    }
    cmd_args[arg_length - 1] = NULL;
    return cmd_args;
}

// Function declarations with prototypes
char* ipc_create(int size);      // Fixed prototype
void ipc_close(void);            // Fixed prototype
double elapsed_time(struct timeval* start, struct timeval* end); // Fixed prototype

int main(int argc, char **argv) {
    pid_t pid;
    int status;
    char** command_args = NULL;
    char* ipc_ptr = NULL; // pointer to shared memory
    struct timeval start_time;
    struct timeval current_time;
    const int SIZE = 16384;
    struct timeval time;

    if (argc < 2) {
        fprintf(stderr, "SYNOPSIS: %s <cmd> <cmd arguments>\n", argv[0]);
        return 1;
    }

    // Create shared memory region
    ipc_ptr = ipc_create(SIZE);
    
    pid = fork();

    if (pid < 0) {  /* error occurred */
        fprintf(stderr, "Fork failed!");
        return 2;
    } else if (pid == 0) {  /* child process */
        // Log start time
        gettimeofday(&time, NULL);

        // Write start time to shared memory
        memcpy(ipc_ptr, &time, sizeof(time));

        // Get arguments and execute the command
        command_args = get_arguments(argc, argv);
        execvp(command_args[0], command_args);

        // If execvp fails
        perror("execvp failed");
        exit(1);
    } else {  /* parent process */
        // Wait for the child process and get status
        waitpid(pid, &status, 0);

        // Get current time
        gettimeofday(&current_time, NULL);

        // Read the start time from shared memory
        memcpy(&start_time, ipc_ptr, sizeof(start_time));

        // Close IPC
        ipc_close();

        // Print the elapsed time
        printf("Elapsed time: %.5f seconds\n", elapsed_time(&start_time, &current_time));

        return status;
    }
}
