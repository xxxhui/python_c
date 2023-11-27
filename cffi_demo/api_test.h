#include <stdio.h>

int add(int a, int b);

typedef struct {
    int x;
    int y;
} Point;

typedef int (*CallbackFunc)(Point *);

void setCallback(CallbackFunc callback);

int calculate(Point *point);

Point getPoint();

Point *getPointRef();
