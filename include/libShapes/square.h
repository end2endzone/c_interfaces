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
    double side;
    void *self;
} Square;

bool is_square(void* addr);
void init_square(Square *s, double side, double x, double y);
