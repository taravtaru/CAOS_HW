#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s command infile outfile\n", argv[0]);
        exit(1);
    }

    pid_t child_pid = fork();
    if (child_pid == 0) {
        int input_fd = open(argv[2], O_RDONLY);
        if (input_fd < 0) { perror("open infile"); exit(1); }
        int output_fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (output_fd < 0) { perror("open outfile"); close(input_fd); exit(1); }
        if (dup2(input_fd, STDIN_FILENO) == -1) { perror("dup2 in"); exit(1); }
        if (dup2(output_fd, STDOUT_FILENO) == -1) { perror("dup2 out"); exit(1); }
        close(input_fd);
        close(output_fd);
        execlp(argv[1], argv[1], NULL);
        perror("execlp");
        exit(1);
    } else {
        int child_status;
        if (wait(&child_status) == -1) {
            perror("wait");
            exit(1);
        }
        printf("WEXITSTATUS: %d\n", WEXITSTATUS(child_status));
    }
    return 0;
}
