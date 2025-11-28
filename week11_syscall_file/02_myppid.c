#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t my_pid, my_ppid;
    my_pid = getpid();
    my_ppid = getppid();
    
    printf("pid: %lu\n", (unsigned long)my_pid);
    printf("ppid: %lu\n", (unsigned long)my_ppid);
    return 0;
}