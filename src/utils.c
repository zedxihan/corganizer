#include "corganizer.h"
#include <string.h>
#include <sys/stat.h>

bool is_valid_directory(const char *path) {
  struct stat path_info;

  if (stat(path, &path_info) != 0)
    return false;

  return S_ISDIR(path_info.st_mode);
}

const char *get_extension(const char *filename) {

  const char *dot;
  dot = strrchr(filename, '.');

  if (dot == NULL || dot == filename)
    return "";

  return dot;
}