#include "libShapes/circle.h"

#include "stdlib.h"
#include "stdio.h"
#include <math.h>

double circle_area(void *self) {
    Circle *c = (Circle *)self;
    return 3.14159 * c->radius * c->radius;
}

double circle_perimeter(void *self) {
    Circle *c = (Circle *)self;
    return 2 * 3.14159 * c->radius;
}

void circle_move(void *self, double dx, double dy) {
    Circle *c = (Circle *)self;
    c->shape.origin_x += dx;
    c->shape.origin_y += dy;
}

void circle_draw(void *self) {
    Circle *c = (Circle *)self;
    printf("Drawing Circle at (%.2f, %.2f) with radius %.2f\n", c->shape.origin_x, c->shape.origin_y, c->radius);
}

void circle_resize(void *self, double factor) {
    Circle *c = (Circle *)self;
    c->radius *= factor;
}

void *circle_clone(void *self) {
    Circle *original = (Circle *)self;
    Circle *copy = malloc(sizeof(Circle));
    if (!copy) return NULL;
    *copy = *original;
    copy->shape.self = copy;
    copy->drawable.self = copy;
    copy->resizable.self = copy;
    copy->cloneable.self = copy;
    return copy;
}

void init_circle(Circle * self, double radius, double x, double y) {
    self->radius = radius;
    self->shape = (Shape){ self, circle_area, circle_perimeter, circle_move, x, y };
    self->drawable = (Drawable){ self, circle_draw };
    self->resizable = (Resizable){ self, circle_resize };
    self->cloneable = (Cloneable){ self, circle_clone };
}
