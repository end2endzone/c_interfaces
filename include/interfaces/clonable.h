#pragma once

typedef struct Cloneable {
    void *self;
    void *(*clone)(void *self);
} Cloneable;
