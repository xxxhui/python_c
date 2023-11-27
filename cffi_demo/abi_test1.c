#include <stdio.h>

typedef int (*CallbackFunc)(int);

void setCallback(CallbackFunc callback) {
    int ret = callback(10);
    printf("来自python结果：%d", ret);
}
