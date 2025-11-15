#pragma once

typedef struct Cloneable {
    void *(*clone)(void *self);
    void *self;
} Cloneable;
