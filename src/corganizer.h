#ifndef CORGANIZER_H
#define CORGANIZER_H

#include <stdbool.h>

bool is_valid_directory(const char *path);
void scan_directory(const char *path);

#endif
