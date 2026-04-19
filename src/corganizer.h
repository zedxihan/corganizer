#ifndef CORGANIZER_H
#define CORGANIZER_H

#include <limits.h>
#include <linux/limits.h>
#include <stdbool.h>

typedef struct FileEntry {
  char source[PATH_MAX];
  char name[256];
  char ext[32];
  char category[64];

  struct FileEntry *next;
} FileEntry;

// prototypes
bool is_valid_directory(const char *path);

FileEntry *scan_directory(const char *path);
void free_list(FileEntry *head);

void preview_moves(FileEntry *head);
void execute_moves(FileEntry *head);

const char *get_extension(const char *filename);
const char *get_category(const char *ext);

#endif
