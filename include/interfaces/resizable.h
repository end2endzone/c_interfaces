#pragma once

typedef struct Resizable {
    void (*scale)(void *self, double factor);
    void *self;
} Resizable;
