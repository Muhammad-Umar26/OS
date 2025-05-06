## Code:

```cpp
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

using namespace std;

void signalHandler(int signum) {
    cout << "In signal handler function" << endl;
    cout << "Signal Generated with Id: " << signum << endl;
}

int main(){
    if(signal(SIGCHLD, signalHandler) == SIG_ERR) {
        cout << "Signal Not successfully initialized";
        return 1;
    }

    pid_t id = fork();

    if(id < 0) return 1;
    
    if(id == 0){
        cout << "In child process" << endl;
    } else {
        wait(NULL);
        cout << "In Parent Process" << endl;
    }

    return 0;
}
```

## ScreenShot:

![image](https://github.com/user-attachments/assets/641f3a16-b453-41dd-8d49-dcee73a26d2b)
