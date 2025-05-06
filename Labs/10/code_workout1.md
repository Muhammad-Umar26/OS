## CodE:

```c
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2

int counter = 0;
pthread_mutex_t mutex;

void* runner(void* args) {
    for(int i = 0; i < 100000; ++i) {
        pthread_mutex_lock(&mutex);
        ++counter;
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t t[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    int i;

    for(i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&t[i], NULL, runner, NULL);
    }

    for(i = 0; i < NUM_THREADS; ++i) {
        pthread_join(t[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Counter: %d\n", counter);
    return 0;
}
```

## ScreenShot:

![image](https://github.com/user-attachments/assets/f61f9b05-a1b3-41e8-8263-d500bfd5af30)
