#pragma once

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
} Square;

void init_square(Square *s, double side, double x, double y);
