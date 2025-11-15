#pragma once

typedef struct Drawable {
    void (*draw)(void *self);
    void *self;
} Drawable;
