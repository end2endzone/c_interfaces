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




inline bool is_clonable_circle(Cloneable* test)
{
#define TEMPLATE_TYPE Circle
#include "is_clonable.body-template.h"
#undef TEMPLATE_TYPE
}

inline bool is_clonable_square(Cloneable* test)
{
#define TEMPLATE_TYPE Square
#include "is_clonable.body-template.h"
#undef TEMPLATE_TYPE
}

inline bool is_clonable_triangle(Cloneable* test)
{
#define TEMPLATE_TYPE Triangle
#include "is_clonable.body-template.h"
#undef TEMPLATE_TYPE
}

// ------------------------------------------

inline bool is_drawable_circle(Drawable* test)
{
#define TEMPLATE_TYPE Circle
#include "is_drawable.body-template.h"
#undef TEMPLATE_TYPE
}

inline bool is_drawable_square(Drawable* test)
{
#define TEMPLATE_TYPE Square
#include "is_drawable.body-template.h"
#undef TEMPLATE_TYPE
}

inline bool is_drawable_triangle(Drawable* test)
{
#define TEMPLATE_TYPE Triangle
#include "is_drawable.body-template.h"
#undef TEMPLATE_TYPE
}

// ------------------------------------------

inline bool is_resizable_circle(Resizable* test)
{
#define TEMPLATE_TYPE Circle
#include "is_resizable.body-template.h"
#undef TEMPLATE_TYPE
}

inline bool is_resizable_square(Resizable* test)
{
#define TEMPLATE_TYPE Square
#include "is_resizable.body-template.h"
#undef TEMPLATE_TYPE
}

inline bool is_resizable_triangle(Resizable* test)
{
#define TEMPLATE_TYPE Triangle
#include "is_resizable.body-template.h"
#undef TEMPLATE_TYPE
}

// ------------------------------------------

inline bool is_shape_circle(Shape* test)
{
#define TEMPLATE_TYPE Circle
#include "is_shape.body-template.h"
#undef TEMPLATE_TYPE
}

inline bool is_shape_square(Shape* test)
{
#define TEMPLATE_TYPE Square
#include "is_shape.body-template.h"
#undef TEMPLATE_TYPE
}

inline bool is_shape_triangle(Shape* test)
{
#define TEMPLATE_TYPE Triangle
#include "is_shape.body-template.h"
#undef TEMPLATE_TYPE
}

// ------------------------------------------


Drawable* as_drawable(void* addr)
{
  if ( is_circle(addr) )
  {
    Circle* temp = (Circle*)addr;
    return &temp->drawable;
  }
  else if ( is_square(addr) )
  {
    Square* temp = (Square*)addr;
    return &temp->drawable;
  }
  else if ( is_triangle(addr) )
  {
    Triangle* temp = (Triangle*)addr;
    return &temp->drawable;
  }
  return NULL;
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
            printf("Is that a Circle ? %d\n", is_circle(copy));
            printf("Is that a Square ? %d\n", is_square(copy));
            printf("Is that a Triangle ? %d\n", is_triangle(copy));
            Drawable* drawable = as_drawable(copy);
            drawable->draw(drawable->self);
            free(copy);
        }
        printf("---------------------------------\n");
    }

    return 0;
}
