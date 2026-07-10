#include "corganizer.h"
#include <stdio.h>
#include <string.h>

#define COLOR_RESET "\033[0m"
#define COLOR_BOLD "\033[1m"
#define COLOR_CYAN "\033[36m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RED "\033[31m"

static const char *row_color(char c) {
  return c == 'y' ? COLOR_YELLOW : c == 'g' ? COLOR_GREEN : c == 'r' ? COLOR_RED : COLOR_RESET;
}

void ui_print_header(const char *title, const char *ct) {
  printf("\n%s%s=== %s ===%s\n", COLOR_BOLD, row_color(ct && *ct ? *ct : ' '), title, COLOR_RESET);
  printf("┌───────────┬────────────────────────────────┬─────────────────┐\n");
  printf("│ %s%-9s%s │ %s%-30s%s │ %s%-15s%s │\n", COLOR_BOLD, "STATUS", COLOR_RESET, COLOR_BOLD,
         "FILE NAME", COLOR_RESET, COLOR_BOLD, "DEST CATEGORY", COLOR_RESET);
  printf("├───────────┼────────────────────────────────┼─────────────────┤\n");
}

void ui_print_row(const char *status, const char *name, const char *category, const char *ct) {
  char c = (ct && *ct) ? *ct : ' ';
  const char *color = row_color(c);
  const char *cat_color = (c == 'r') ? COLOR_RED : COLOR_CYAN;

  size_t len = strlen(name);
  int field_width = (len > 30) ? 27 : 30;
  const char *dots = (len > 30) ? "..." : "";

  printf("│ %s%-9s%s │ %-*.*s%s │ %s%-15s%s │\n", color, status, COLOR_RESET, field_width,
         field_width, name, dots, cat_color, category, COLOR_RESET);
}

void ui_print_footer(void) {
  printf("└───────────┴────────────────────────────────┴─────────────────┘\n\n");
}
