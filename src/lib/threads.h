#include <pthread.h>

typedef pthread_t Thread;

Thread renderer_thread;

int createThread(Thread* thread, any(*routine)(any), any arg) {
    pthread_create(thread, NULL, routine, arg);
}

void revokeThread(Thread thread) {
    if (thread == renderer_thread) showConsoleCursor();
    pthread_cancel(thread);
}

void terminateThread() {
    pthread_exit(NULL);
}

void await(Thread thread) {
    pthread_join(thread, NULL);
}
