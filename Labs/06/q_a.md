## Code:

```c
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 01

int main() {
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    int pid;

    if(pipe(fd) == -1) {
        printf("Pipe failed\n");
        return 1;
    }

    pid = fork();
    if(pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if(pid > 0) {
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        printf("Parent process Id: %d\n", getpid());
        close(fd[WRITE_END]);
    } else {
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("read %s\n", read_msg);
        printf("Child process Id: %d\n", getpid());
        close(fd[READ_END]);
    }
    return 0;
}
```

## Output

![image](https://github.com/user-attachments/assets/2b1a206c-fb05-4f60-a0cb-4b48e1ff327d)
