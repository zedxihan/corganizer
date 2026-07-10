#include "corganizer.h"

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

static void build_paths(const FileEntry *node, char *folder, char *target);

// preview mode
void preview_moves(FileEntry *head) {
  ui_print_header("PREVIEW MODE: No files will be moved", "yellow");

  while (head) {
    ui_print_row("PREVIEW", head->name, head->category, "yellow");
    head = head->next;
  }
  ui_print_footer();
}

// execute mode
void execute_moves(FileEntry *head) {
  ui_print_header("ORGANIZING FILES", "green");

  while (head) {
    char folder[PATH_MAX];
    char target[PATH_MAX];
    build_paths(head, folder, target);

    mkdir(folder, 0755);

    if (rename(head->source, target) == 0) {
      ui_print_row("SUCCESS", head->name, head->category, "green");
    } else {
      ui_print_row("FAILED", head->name, "ERROR", "red");
    }

    head = head->next;
  }
  ui_print_footer();
}

// helper function
static void build_paths(const FileEntry *node, char *folder, char *target) {
  const char *last_slash = strrchr(node->source, '/');
  size_t dir_len = last_slash ? (size_t)(last_slash - node->source) : 0;

  if (dir_len > 0)
    snprintf(folder, PATH_MAX, "%.*s/%s", (int)dir_len, node->source, node->category);
  else
    snprintf(folder, PATH_MAX, "%s", node->category);

  size_t room = PATH_MAX - strlen(node->name) - 2;
  if (room > 0)
    snprintf(target, PATH_MAX, "%.*s/%s", (int)room, folder, node->name);
  else
    target[0] = '\0';
}
