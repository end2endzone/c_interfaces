#pragma once

typedef struct Resizable {
    void *self;
    void (*scale)(void *self, double factor);
} Resizable;
