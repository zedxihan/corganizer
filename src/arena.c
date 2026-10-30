#include "corganizer.h"

#include <stdlib.h>

bool arena_init(Arena *arena, size_t capacity) {
    arena->base = malloc(capacity);
    arena->used = 0;
    arena->capacity = capacity;
    return arena->base != NULL;
}

void *arena_alloc(Arena *arena, size_t size) {
    if (size > arena->capacity - arena->used)
        return NULL;

    void *ptr = arena->base + arena->used;
    arena->used += size;
    return ptr;
}

void arena_release(Arena *arena) {
    free(arena->base);
    arena->base = NULL;
    arena->used = 0;
    arena->capacity = 0;
}
