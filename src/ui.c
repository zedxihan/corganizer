#include "corganizer.h"

#include <stdio.h>
#include <string.h>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

#define NAME_WIDTH 30

static const struct {
    const char *label;
    const char *color;
} status_style[STATUS_COUNT] = {
    [STATUS_PENDING] = {"PREVIEW", YELLOW},
    [STATUS_MOVED] = {"MOVED", GREEN},
    [STATUS_SKIPPED] = {"SKIPPED", YELLOW},
    [STATUS_FAILED] = {"FAILED", RED},
};

void ui_print_header(bool run) {
    printf("\n%s%s=== %s ===%s\n", BOLD, run ? GREEN : YELLOW,
           run ? "ORGANIZING FILES" : "PREVIEW MODE: No files will be moved",
           RESET);
    printf(
        "┌───────────┬────────────────────────────────┬─────────────────┐\n");
    printf("│ %s%-9s%s │ %s%-30s%s │ %s%-15s%s │\n", BOLD, "STATUS", RESET,
           BOLD, "FILE NAME", RESET, BOLD, "DEST CATEGORY", RESET);
    printf(
        "├───────────┼────────────────────────────────┼─────────────────┤\n");
}

void ui_print_row(const FileEntry *entry) {
    const char *label = status_style[entry->status].label;
    const char *color = status_style[entry->status].color;

    // 27 characters plus "..."
    bool too_long = strlen(entry->name) > NAME_WIDTH;
    int shown = too_long ? NAME_WIDTH - 3 : NAME_WIDTH;

    printf("│ %s%-9s%s │ %-*.*s%s │ %s%-15s%s │\n", color, label, RESET, shown,
           shown, entry->name, too_long ? "..." : "", CYAN, entry->category,
           RESET);
}

void ui_print_footer(const FileList *list) {
    size_t counts[STATUS_COUNT] = {0};
    for (size_t i = 0; i < list->count; i++)
        counts[list->entries[i].status]++;

    printf(
        "└───────────┴────────────────────────────────┴─────────────────┘\n");
    printf("%zu files", list->count);
    if (counts[STATUS_PENDING] != list->count)
        printf(": %zu moved, %zu skipped, %zu failed", counts[STATUS_MOVED],
               counts[STATUS_SKIPPED], counts[STATUS_FAILED]);
    printf("\n\n");
}
