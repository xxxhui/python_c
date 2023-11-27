#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int calculate(Point *point) {
    return point->x + point->y;
}
