#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char ** argv)
{
    pid_t pid = fork();
    
    if (pid == 0) { // we are in the child process
        printf("Hello from the child process!\n");
        exit (0); // terminates the child process
    } else {
        // now in the parent process
        waitpid(pid, NULL, 0);
        printf("The child process has exited. Hello from the parent!\n");
    }
    
    return 0;
}
