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
    STATUS_COUNT, // number
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

// prototypes and func calls
// arena
bool arena_init(Arena *arena, size_t capacity);
void *arena_alloc(Arena *arena, size_t size);
void arena_release(Arena *arena);

// rules
const char *get_category(const char *filename);

// scan
bool scan_directory(const char *dir_path, FileList *list);
void list_release(FileList *list);

// ui
void ui_print_header(bool run);
void ui_print_row(const FileEntry *entry);
void ui_print_footer(const FileList *list);

#endif
