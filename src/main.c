#include "corganizer.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./corganizer <scan | run> <folder>\n");
    return 1;
  }

  if (strcmp(argv[1], "scan") != 0 && strcmp(argv[1], "run") != 0) {
    printf("Error: Mode must be 'scan' or 'run'\n");
    return 1;
  }

  if (!is_valid_directory(argv[2])) {
    printf("Error: Invalid directory\n");
    return 1;
  }

  printf("Mode: %s\n\n", argv[1]);

  // function calls
  FileEntry *list = scan_directory(argv[2]);

  if (!list) {
    printf("No files to organize or unable to read directory\n");
    return 0;
  }

  if (strcmp(argv[1], "scan") == 0)
    preview_moves(list);
  else
    execute_moves(list);

  // free memory
  free_list(list);

  return 0;
}
