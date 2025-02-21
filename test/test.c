#include <pthread.h>
#include <stdio.h>

#define MAX_LOOP 100000000 // 1亿次

int counter = 0;

// 无锁保护的累加函数
void *increment(void *arg) {
    for (int i = 0; i < MAX_LOOP; ++i) {
        int temp = counter;
        temp = temp + 1;
        counter = temp;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // 创建两个线程
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // 等待线程结束
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // 理论值应为2,000,000，实际会有偏差
    printf("Final counter value: %d (expected 2000000)\n", counter);

    return 0;
}
