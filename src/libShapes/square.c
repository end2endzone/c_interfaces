#include "libShapes/square.h"

#include "stdlib.h"
#include "stdio.h"

double square_area(void *self) {
    Square *s = (Square *)self;
    return s->side * s->side;
}

double square_perimeter(void *self) {
    Square *s = (Square *)self;
    return 4 * s->side;
}

void square_move(void *self, double dx, double dy) {
    Square *s = (Square *)self;
    s->shape.origin_x += dx;
    s->shape.origin_y += dy;
}

void square_draw(void *self) {
    Square *s = (Square *)self;
    printf("Drawing Square at (%.2f, %.2f) with side %.2f\n", s->shape.origin_x, s->shape.origin_y, s->side);
}

void square_resize(void *self, double factor) {
    Square *s = (Square *)self;
    s->side *= factor;
}

void *square_clone(void *self) {
    Square *original = (Square *)self;
    Square *copy = malloc(sizeof(Square));
    if (!copy) return NULL;
    *copy = *original;
    copy->shape.self = copy;
    copy->drawable.self = copy;
    copy->resizable.self = copy;
    copy->cloneable.self = copy;
    return copy;
}

void init_square(Square * self, double side, double x, double y) {
    self->side = side;
    self->shape = (Shape){ self, square_area, square_perimeter, square_move, x, y };
    self->drawable = (Drawable){ self, square_draw };
    self->resizable = (Resizable){ self, square_resize };
    self->cloneable = (Cloneable){ self, square_clone };
}
