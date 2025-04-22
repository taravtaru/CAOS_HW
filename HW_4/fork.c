#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == 0) {
        printf("Hello from Child\n");
        pid_t grandchild_pid = fork();
        if (grandchild_pid == 0) {
            printf("Hello from Grandchild\n");
        } else {
            wait(NULL);
        }
    } else {
        wait(NULL);
        printf("Hello from Parent\n");
    }
    return 0;
}
