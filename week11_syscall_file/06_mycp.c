#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 32

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s [source file] [destination file1] [destination file2] ... \n", argv[0]);
        exit(0);
    }

    // open source file (read only)
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror(argv[1]);
        exit(0);
    }

    // open dest files
    int num_files = argc - 2;
    int* dest_fd_list = (int*)malloc(sizeof(int) * num_files);
    for (int i = 0; i < num_files; i++) {
        dest_fd_list[i] = open(argv[i+2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (dest_fd_list[i] == -1) {
            perror(argv[i+2]);
        }
    }

    // read from source and write destinations & stdout
    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;
    while(1) {
        read_result = read(src_fd, readStr, BUF_SIZE);
        if (read_result == 0) {
            printf("program end...\n");
            break;
        }
        
        write(STDOUT_FILENO, readStr, read_result);
        for (int i = 0; i < num_files; i++) {
            write(dest_fd_list[i], readStr, read_result);
        }
    }

    // close all files
    close(src_fd);
    for (int i = 0; i < num_files; i++) {
        if (dest_fd_list[i] != -1) {
            close(dest_fd_list[i]);
        }
    }

    // free
    free(readStr);
    free(dest_fd_list);
    return 0;
}