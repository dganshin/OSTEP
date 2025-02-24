#include <assert.h>  // 断言检查头文件
#include <pthread.h> // POSIX线程库头文件
#include <stdio.h>   // 标准输入输出头文件

/* 线程函数模板（必须符合void*返回值类型）
 * arg: 通用指针参数，可接收任意类型的数据地址
 * 返回值: 通用指针，可用于向主线程返回数据 */
void *mytread(void *arg) {
    // 将void*参数转换为char*类型后打印
    printf("%s\n", (char *)arg);
    return NULL; // 返回空指针（不返回数据）
}

int main() {
    pthread_t p1, p2; // 线程句柄（标识线程的对象）
    int rc;           // 用于接收系统调用返回值

    printf("main:begin\n");

    /* 创建线程1
     * 参数1: 线程句柄地址
     * 参数2: 线程属性（NULL表示默认）
     * 参数3: 线程函数指针
     * 参数4: 传递给线程函数的参数 */
    rc = pthread_create(&p1, NULL, mytread, "A");
    assert(rc == 0); // 验证线程创建是否成功（0表示成功）

    // 创建线程2（参数同理）
    rc = pthread_create(&p2, NULL, mytread, "B");
    assert(rc == 0);

    /* 等待线程1结束
     * 参数2: 用于接收线程返回值的指针（NULL表示不接收） */
    rc = pthread_join(p1, NULL);
    assert(rc == 0);

    // 等待线程2结束
    rc = pthread_join(p2, NULL);
    assert(rc == 0);

    printf("main:end\n");
    return 0;
}