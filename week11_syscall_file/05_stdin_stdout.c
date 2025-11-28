#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 128

int main(int argc, char* argv[])
{
    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        exit(0);
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;
    while(1) {
        read_result = read(STDIN_FILENO, readStr, BUF_SIZE);
        if (read_result == 0) {
            printf("Detected EOF (Ctrl + D)\n");
            printf("Terminating read loop...\n");
            break;
        }
        write(STDOUT_FILENO, readStr, read_result);
    }

    free(readStr);

    return 0;
}