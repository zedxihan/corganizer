#include "corganizer.h"

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

static void build_paths(const FileEntry *node, char *folder, char *target);

// preview mode
void preview_moves(FileEntry *head) {
  printf("PREVIEW MODE: No files will be moved\n");

  while (head) {
    char folder[PATH_MAX];
    char target[PATH_MAX];
    build_paths(head, folder, target);

    printf("[PREVIEW] %s -> %s\n", head->name, target);
    head = head->next;
  }
}

// execute mode
void execute_moves(FileEntry *head) {
  while (head) {
    char folder[PATH_MAX];
    char target[PATH_MAX];
    build_paths(head, folder, target);

    mkdir(folder, 0755);

    if (rename(head->source, target) == 0) {
      printf("[MOVED] %s -> %s/\n", head->name, head->category);
    } else {
      perror("[FAIL] Error moving file\n");
      printf("File: %s\n", head->name);
    }

    head = head->next;
  }
}

// helper function
static void build_paths(const FileEntry *node, char *folder, char *target) {
  const char *last_slash = strrchr(node->source, '/');
  size_t dir_len = last_slash ? (size_t)(last_slash - node->source) : 0;

  if (dir_len > 0)
    snprintf(folder, PATH_MAX, "%.*s/%s", (int)dir_len, node->source, node->category);
  else
    snprintf(folder, PATH_MAX, "%s", node->category);

  snprintf(target, PATH_MAX, "%s/%s", folder, node->name);
}
