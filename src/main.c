#include "corganizer.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

static void print_usage(void) {
  fprintf(stderr, "Usage: corganizer [options] <folder>\n"
                  "  -r, --run     move the files (default: preview only)\n"
                  "  -h, --help    show this help\n");
}

int main(int argc, char *argv[]) {
  bool run = false;

  static const struct option long_opts[] = {
      {.name = "run", .has_arg = no_argument, .val = 'r'},
      {.name = "help", .has_arg = no_argument, .val = 'h'},
      {0}};

  int opt;
  while ((opt = getopt_long(argc, argv, "rh", long_opts, NULL)) != -1) {
    switch (opt) {
    case 'r':
      run = true;
      break;
    case 'h':
      print_usage();
      return EXIT_SUCCESS;
    default:
      print_usage();
      return EXIT_FAILURE;
    }
  }

  if (optind != argc - 1) {
    print_usage();
    return EXIT_FAILURE;
  }
  const char *folder = argv[optind];

  // TODO: the FileList declare and function calls

  return EXIT_SUCCESS;
}
