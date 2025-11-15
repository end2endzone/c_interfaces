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
    double radius;
} Circle;

void init_circle(Circle *c, double radius, double x, double y);
