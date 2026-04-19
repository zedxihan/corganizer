#include "corganizer.h"

#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

static FileEntry *create_entry(const char *full_path, const char *filename);

// scan directory
FileEntry *scan_directory(const char *dir) {
  DIR *folder = opendir(dir);
  if (!folder) {
    perror("opendir");
    return NULL;
  }

  struct dirent *entry;
  struct stat info;
  char full_path[PATH_MAX];

  FileEntry *head = NULL;
  FileEntry *tail = NULL;

  while ((entry = readdir(folder)) != NULL) {
    if (entry->d_name[0] == '.')
      continue;

    snprintf(full_path, PATH_MAX, "%s/%s", dir, entry->d_name);

    if (stat(full_path, &info) != 0 || !S_ISREG(info.st_mode))
      continue;

    FileEntry *node = create_entry(full_path, entry->d_name);

    if (node) {
      if (!head)
        head = node;
      else
        tail->next = node;
      tail = node;
    }
  }

  closedir(folder);
  return head;
}

// free linked list
void free_list(FileEntry *head) {
  while (head) {
    FileEntry *next = head->next;
    free(head);
    head = next;
  }
}

// helper function
static FileEntry *create_entry(const char *full_path, const char *filename) {
  FileEntry *node = malloc(sizeof(*node));

  if (!node) {
    perror("malloc");
    return NULL;
  }

  const char *ext = get_extension(filename);
  const char *category = get_category(ext);

  snprintf(node->source, sizeof(node->source), "%s", full_path);
  snprintf(node->name, sizeof(node->name), "%s", filename);
  snprintf(node->ext, sizeof(node->ext), "%s", ext);
  snprintf(node->category, sizeof(node->category), "%s", category);

  node->next = NULL;
  return node;
}