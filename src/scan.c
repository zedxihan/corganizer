#include "corganizer.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void scan_directory(const char *path) {
  struct dirent *entry;

  DIR *folder = opendir(path);

  if (folder == NULL) {
    printf("Error: Cannot read directoryn");
    return;
  }

  while ((entry = readdir(folder)) != NULL) {
    char fullpath[1024];
    struct stat info;

    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;

    snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

    if (stat(fullpath, &info) != 0)
      continue;

    if (S_ISDIR(info.st_mode))
      printf("[DIR] %s\n", entry->d_name);
    else
      printf("[FILE] %s\n", entry->d_name);
  }

  closedir(folder);
}
