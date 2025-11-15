#include "libShapes/circle.h"
#include "libShapes/square.h"
#include "libShapes/Triangle.h"

#include "stdlib.h"
#include "stdio.h"
#include <stdbool.h>

void print_area(Shape* s)
{
  printf("Area: %.2f\n", s->area(s->self));
}

void print_perimeter(Shape* s)
{
  printf("Perimeter: %.2f\n", s->perimeter(s->self));
}

void render(Drawable* d)
{
  d->draw(d->self);
}

void apply_scale(Resizable* r, double factor)
{
  r->scale(r->self, factor);
}

void move_shape(Shape* s, double dx, double dy)
{
  s->move(s->self, dx, dy);
}

void* clone(Cloneable* c)
{
  return c->clone(c->self);
}

int main() {
    Circle c;
    Square s;
    Triangle t;

    init_circle(&c, 5.0, 0.0, 0.0);
    init_square(&s, 4.0, 10.0, 10.0);
    init_triangle(&t, 3.0, 4.0, 5.0, 6.0, -5.0, -5.0);

    Shape *shapes[] = { &c.shape, &s.shape, &t.shape };
    Drawable *drawables[] = { &c.drawable, &s.drawable, &t.drawable };
    Resizable *resizables[] = { &c.resizable, &s.resizable, &t.resizable };
    Cloneable *clonables[] = { &c.cloneable, &s.cloneable, &t.cloneable };

    for (int i = 0; i < 3; i++) {
        print_area(shapes[i]);
        print_perimeter(shapes[i]);
        render(drawables[i]);
        move_shape(shapes[i], 1.0, 2.0);
        apply_scale(resizables[i], 1.5);

        void *copy = clone(clonables[i]);
        if (copy) {
            printf("Cloned address: 0x%p\n", copy);
            free(copy);
        }
        printf("---------------------------------\n");
    }

    return 0;
}
