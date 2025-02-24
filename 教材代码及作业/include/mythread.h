#include <pthread.h>

void Pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                    void *(*start_routine)(void *), void *arg);

// void Pthread_join(pthread_t thread, void **value_ptr);
