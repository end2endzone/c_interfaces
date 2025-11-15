#pragma once

typedef struct Drawable {
    void *self;
    void (*draw)(void *self);
} Drawable;
