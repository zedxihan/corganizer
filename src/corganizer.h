#ifndef CORGANIZER_H
#define CORGANIZER_H

#include <stdbool.h>

bool is_valid_directory(const char *path);

void scan_directory(const char *path);
void organize_directory(const char *path);

const char *get_extension(const char *filename);
const char *get_category(const char *ext);

#endif
