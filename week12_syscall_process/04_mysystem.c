    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <stdlib.h>
    #include <sys/wait.h>

    int mysystem(const char *command)
    {
        pid_t child_pid = fork();

        if (child_pid == 0) { // child
            execl("/bin/sh", "sh", "-c", command, NULL);
            exit(127);
        }
        else { // parent
            int wstatus;
            waitpid(child_pid, &wstatus, 0);

            if (WIFEXITED(wstatus)) {
                return WEXITSTATUS(wstatus);
            }
        }

        return -1;
    }

    int main(void)
    {
        // system("ls -l | wc -l");
        // system("find . -name '*.c'");

        mysystem("ls -l | wc -l");
        mysystem("find . -name '*.c'");

        printf("Good Bye~\n");

        return 0;
    }