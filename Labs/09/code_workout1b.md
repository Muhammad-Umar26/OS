## Code:

```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void sigint_handler(int signum) {
    printf("Ctrl+C (SIGINT) received. Exiting...\n");
    // Perform cleanup or other necessary tasks before exiting
    exit(signum);
}

int main() {
    // Set up the signal action structure
    struct sigaction sa;
    sa.sa_handler = sigint_handler;   // Specify the signal handler function
    sigemptyset(&sa.sa_mask);         // Clear the signal mask
    sa.sa_flags = 0;                  // No special flags

    // Register the signal handler for SIGINT using sigaction
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return EXIT_FAILURE;
    }

    // Loop indefinitely to keep the program running
    while(1) {
        // Do some work or wait for further input
        sleep(1);
    }

    return EXIT_SUCCESS;
}
```

## ScreenShot:

![image](https://github.com/user-attachments/assets/91335dd0-77d1-446b-a3dc-6bde03d13641)
