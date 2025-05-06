## Code:

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signalHandler(int signum) {
  printf("Caught SIGINT signal: %d\n", signum);
  exit(0);
}

int main() {
  if(signal(SIGINT, signalHandler) == SIG_ERR) {
    printf("Error setting up signal handler\n");
  }

  printf("Press Ctrl+C to send SIGINT signal\n");

  while(1) {
    sleep(1);
  }

  return 0;
}
```

## ScreenShot:

![image](https://github.com/user-attachments/assets/8b0d2395-8ca0-40ee-a772-00701c316299)
