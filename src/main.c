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

  if (strcmp(argv[1], "scan") == 0)
    scan_directory(argv[2]);
  else
    organize_directory(argv[2]);

  return 0;
}
