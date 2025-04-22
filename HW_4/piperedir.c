#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s command1 command2 [args_for_command2...]\n", argv[0]);
        exit(1);
    }

    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t producer_pid = fork();
    if (producer_pid < 0) {
        perror("fork pid1");
        exit(1);
    }
    if (producer_pid == 0) {
        if (dup2(pipe_fds[1], STDOUT_FILENO) == -1) { perror("dup2 pid1"); exit(1); }
        close(pipe_fds[0]);
        close(pipe_fds[1]);
        execlp(argv[1], argv[1], NULL);
        perror("execlp command1");
        exit(1);
    }

    pid_t consumer_pid = fork();
    if (consumer_pid < 0) {
        perror("fork pid2");
        exit(1);
    }
    if (consumer_pid == 0) {
        if (dup2(pipe_fds[0], STDIN_FILENO) == -1) { perror("dup2 pid2"); exit(1); }
        close(pipe_fds[1]);
        close(pipe_fds[0]);
        execvp(argv[2], &argv[2]);
        perror("execvp command2");
        exit(1);
    }

    close(pipe_fds[0]);
    close(pipe_fds[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}