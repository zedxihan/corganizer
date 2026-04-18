#include "corganizer.h"
#include <dirent.h>
#include <linux/limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

static void handle_file(const char *path, const char *name, bool move_files) {

  char source[PATH_MAX];
  char folder[PATH_MAX];
  char target[PATH_MAX];

  const char *ext = get_extension(name);
  const char *category = get_category(ext);

  snprintf(source, sizeof(source), "%s/%s", path, name);
  snprintf(folder, sizeof(folder), "%s/%s", path, category);
  snprintf(target, sizeof(target), "%s/%s/%s", path, category, name);

  if (!move_files) {
    printf("[MOVE] %s -> %s/%s\n", name, category, name);
    return;
  }

  mkdir(folder, 0755);

  if (rename(source, target) == 0)
    printf("[DONE] %s -> %s/%s\n", name, category, name);
  else
    printf("[FAIL] %s\n", name);
}

static void process_directory(const char *path, bool move_files) {
  struct dirent *entry;

  DIR *folder = opendir(path);

  if (folder == NULL) {
    printf("Error: Cannot read directory\n");
    return;
  }

  while ((entry = readdir(folder)) != NULL) {
    char fullpath[PATH_MAX];
    struct stat info;

    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;
    if (entry->d_name[0] == '.')
      continue;

    snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

    if (stat(fullpath, &info) != 0)
      continue;
    if (S_ISDIR(info.st_mode))
      continue;

    handle_file(path, entry->d_name, move_files);
  }
  closedir(folder);
}

void scan_directory(const char *path) { process_directory(path, false); }

void organize_directory(const char *path) { process_directory(path, true); }
