#include "api_test.h"

int add(int a, int b) {
    return a+b;
}

int calculate(Point *point) {
    return point->x + point->y;
}

void setCallback(CallbackFunc callback) {
    Point point;
    point.x = 10;
    point.y = 20;
    printf("回调python：point.x = %d，point.y = %d", point.x, point.y);
    int ret = callback(&point);
    printf("来自python结果：%d", ret);
}

Point getPoint() {
    Point p;
    p.x = 1;
    p.y = 2;
    return p;
}

Point mPoint;
Point *getPointRef() {
    mPoint.x = 100;
    mPoint.y = 200;
    return &mPoint;
}
