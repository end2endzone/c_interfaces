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
    double radius;
    void *self;
} Circle;

bool is_circle(void* addr);
void init_circle(Circle *c, double radius, double x, double y);
