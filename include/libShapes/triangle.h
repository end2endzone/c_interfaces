#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "interfaces/clonable.h"
#include "interfaces/drawable.h"
#include "interfaces/resizable.h"
#include "interfaces/shape.h"

typedef struct {
    Shape shape;
    Drawable drawable;
    Resizable resizable;
    Cloneable cloneable;
    double base, height, side_a, side_b;
    void *self;
} Triangle;

bool is_triangle(void* addr);
void init_triangle(Triangle *t, double base, double height, double side_a, double side_b, double x, double y);
