#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s command output_file\n", argv[0]);
        exit(1);
    }
    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd < 0) {
        perror("open");
        exit(1);
    }
    if (dup2(output_fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        close(output_fd);
        exit(1);
    }
    close(output_fd);
    execlp(argv[1], argv[1], NULL);
    perror("execlp");
    return 1;
}
