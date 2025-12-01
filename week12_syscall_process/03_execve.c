#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *const argv[])
{
    if (argc < 2) {
        printf("Usage: ./03_execve <program path> [OPTION] ...\n");
        return 0;
    }

    pid_t child_pid = fork();

    if (child_pid == 0) { // child
        execve(argv[1], &argv[1], NULL);
        return 1; // fail
    }
    else { // parent
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
        printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
    }

    return 0;
}