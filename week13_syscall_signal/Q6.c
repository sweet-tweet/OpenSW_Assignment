#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void)
{
    sigset_t block_set, pending_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);

    sigprocmask(SIG_BLOCK, &block_set, NULL);

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");

    sleep(5);

    sigpending(&pending_set);

    if (sigismember(&pending_set, SIGINT) == 1) {
        printf("\nSIGINT is pendig\n");
    }
    else {
        printf("\nSIGINT is not pending\n");
    }

    return 0;
}