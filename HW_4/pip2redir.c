#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s command1 command2 [args_for_command2...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t producer_pid = fork();
    if (producer_pid < 0) {
        perror("fork for command1");
        exit(EXIT_FAILURE);
    } else if (producer_pid == 0) {
        dup2(pipe_fds[1], STDOUT_FILENO);
        close(pipe_fds[0]);
        close(pipe_fds[1]);
        execlp(argv[1], argv[1], NULL);
        perror("execlp command1");
        exit(EXIT_FAILURE);
    }

    pid_t consumer_pid = fork();
    if (consumer_pid < 0) {
        perror("fork for command2");
        exit(EXIT_FAILURE);
    } else if (consumer_pid == 0) {
        dup2(pipe_fds[0], STDIN_FILENO);
        close(pipe_fds[1]);
        close(pipe_fds[0]);
        execvp(argv[2], &argv[2]);
        perror("execvp command2");
        exit(EXIT_FAILURE);
    }

    close(pipe_fds[0]);
    close(pipe_fds[1]);

    int child_status;
    pid_t finished_pid;
    while ((finished_pid = wait(&child_status)) > 0) {
        printf("Process %d exited with status %d\n", finished_pid, WEXITSTATUS(child_status));
    }
    if (finished_pid == -1 && errno != ECHILD) {
        perror("wait");
        exit(EXIT_FAILURE);
    }

    return 0;
}