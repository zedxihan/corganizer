#ifndef CORGANIZER_H
#define CORGANIZER_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_FILES 100000
#define ARENA_CAPACITY (16 * 1024 * 1024) // 16 MB

typedef enum {
    STATUS_PENDING,
    STATUS_MOVED,
    STATUS_SKIPPED,
    STATUS_FAILED,
} Status;

typedef struct {
    char *base;
    size_t used;
    size_t capacity;
} Arena;

typedef struct {
    const char *path; // full path
    const char *name; // a.pdf
    const char *category;
    Status status;
} FileEntry;

typedef struct {
    FileEntry *entries;
    size_t count;
    Arena string_arena;
} FileList;

// TODO: prototypes and func calls

// rules
const char *get_category(const char *filename);

#endif
