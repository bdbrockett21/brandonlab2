// TODO: add the appropriate head files here
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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


int main(int argc, char** argv)
{
    pid_t pid;
    int status;
    char* command = NULL;
    char** command_args = NULL;
    char* ipc_ptr = NULL; // pointer to shared memory
    struct timeval start_time;
    struct timeval current_time;

    if (argc < 2){
        fprintf(stderr,"SYNOPSIS: %s <cmd> <cmd arguments>\n",argv[0]);
        return 1;
    }
    
    // TODO: call ipc_create to create shared memory region to which parent
    //       child have access.
    int fd = shm_open("brandonlab2",O_CREAT | O_RDWR,0666);
    if (fd == -1);
    perror("shm_open");
    return NULL;
}
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
}
    return ptr;

    ipc_ptr = ipc_create (sizeof(struct timeval));
    if(ipc_ptr == NULL) {
        fprintf(stderr, "Failed to create shared memory\n")
        return 1;
    }

    if(pid == 0){
        gettimeofday(&start_time, NULL)
        memcpy(ipc_ptr, &start_time,sizeof(struct timeval));
        //Execute command using execyp
    }else // parent process
    wait(&status);
    gettimeofday(&current_time, NULL);
    memcpy(&start_time, ipc_ptr, sizeof(strict timeval));
    ipc_close();
    printf("Elapsed time %.5f\n", elapsed_time(&start_time, &current_time));
    

    /* fork a child process */
    pid = fork();

    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork failed!");
        return 2;
    }
    else if (pid == 0) { /*child process */
        // TODO: use gettimeofday to log the start time
          int fd = shm_open("brandonlab2",O_CREAT | O_RDWR,0666);
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

        //Log the start time 
        struct timeval start_time;
        gettimeofday(&start_time, NULL);
        memcpy(ptr, &start_time, sizeof(struct timeval));

        return ptr;
    }

        char* ipc_ptr = ipc_create(sizeof(struct timeval));
        if (ipc_ptr == NULL) {
        fprintf(stderr, "Failed to create shared memory\n");
        return 1;
    }
        //Execute the command using execvp()
        if (pid == 0) { /* child process */
        struct timeval start_time;
        gettimeofday(&start_time, NULL);
        memcpy(ipc_ptr, &start_time, sizeof(struct timeval));
    
}else{
    wait(&status);
    struct timeval start_time, current_time;
    gettimeofday(&current_time, NULL);
    memcpy(&start_time, ipc_ptr sizeof(struct timeval));
    ipc_close();
    printf("Elapsed time %.5f/n")
}



        // TODO: write the time to the IPC
        
        // TODO: get the list of arguments to be used in execvp() and 
        // execute execvp()

    }
    else { /* parent process */
        // TODO: have parent wait and get status of child.
        //       Use the variable status to store status of child. 
        
        // TODO: get the current time using gettimeofday
        
        // TODO: read the start time from IPC
        
        // TODO: close IPC

        // NOTE: DO NOT ALTER THE LINE BELOW.
        printf("Elapsed time %.5f\n",elapsed_time(&start_time, &current_time));
    }
    
    return status;
}