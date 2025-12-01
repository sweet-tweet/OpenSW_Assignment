#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid == 0) { // child process
        sleep(1);

        printf("Child process PID: %lu\n", (unsigned long)getpid());
        printf("Child process PPID: %lu\n", (unsigned long)getppid());

        return 7;
    }
    else { // parent process
        int wstatus;
        if (WIFEXITED(wstatus)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
        }
        
        printf("Parent process PID: %lu\n", (unsigned long)getpid());
        printf("Parent process PPID: %lu\n", (unsigned long)getppid());
    }
    
    return 0;
}