#pragma once

typedef struct Shape {
    void *self;
    double (*area)(void *self);
    double (*perimeter)(void *self);
    void (*move)(void *self, double move_x, double move_y);
    double origin_x;
    double origin_y;
} Shape;
