#include "libShapes/triangle.h"

#include "stdlib.h"
#include "stdio.h"

double triangle_area(void *self) {
    Triangle *t = (Triangle *)self;
    return 0.5 * t->base * t->height;
}

double triangle_perimeter(void *self) {
    Triangle *t = (Triangle *)self;
    return t->base + t->side_a + t->side_b;
}

void triangle_move(void *self, double dx, double dy) {
    Triangle *t = (Triangle *)self;
    t->shape.origin_x += dx;
    t->shape.origin_y += dy;
}

void triangle_draw(void *self) {
    Triangle *t = (Triangle *)self;
    printf("Drawing Triangle at (%.2f, %.2f) with base %.2f and height %.2f\n",
           t->shape.origin_x, t->shape.origin_y, t->base, t->height);
}

void triangle_resize(void *self, double factor) {
    Triangle *t = (Triangle *)self;
    t->base *= factor;
    t->height *= factor;
    t->side_a *= factor;
    t->side_b *= factor;
}

void *triangle_clone(void *self) {
    Triangle *original = (Triangle *)self;
    Triangle *copy = malloc(sizeof(Triangle));
    if (!copy) return NULL;
    *copy = *original;
    copy->shape.self = copy;
    copy->drawable.self = copy;
    copy->resizable.self = copy;
    copy->cloneable.self = copy;
    return copy;
}

void init_triangle(Triangle *self, double base, double height, double side_a, double side_b, double x, double y) {
    self->base = base;
    self->height = height;
    self->side_a = side_a;
    self->side_b = side_b;
    self->shape = (Shape){ self, triangle_area, triangle_perimeter, triangle_move, x, y };
    self->drawable = (Drawable){ self, triangle_draw };
    self->resizable = (Resizable){ self, triangle_resize };
    self->cloneable = (Cloneable){ self, triangle_clone };
}
