#define _GNU_SOURCE
#include "corganizer.h"

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <sys/stat.h>

static Status move_file(const FileEntry *entry) {
    char folder[PATH_MAX];
    char target[PATH_MAX];

    int dir_len = entry->name - entry->path;

    int n1 = snprintf(folder, sizeof(folder), "%.*s%s", dir_len, entry->path,
                      entry->category);
    int n2 = snprintf(target, sizeof(target), "%s/%s", folder, entry->name);
    if (n1 >= (int)sizeof(folder) || n2 >= (int)sizeof(target))
        return STATUS_FAILED;

    if (mkdir(folder, 0755) != 0 && errno != EEXIST)
        return STATUS_FAILED;

    if (renameat2(AT_FDCWD, entry->path, AT_FDCWD, target, RENAME_NOREPLACE) ==
        0)
        return STATUS_MOVED;

    return errno == EEXIST ? STATUS_SKIPPED : STATUS_FAILED;
}

void organize_files(FileList *list, bool run) {
    ui_print_header(run);

    for (size_t i = 0; i < list->count; i++) {
        FileEntry *entry = &list->entries[i];
        if (run)
            entry->status = move_file(entry);
        ui_print_row(entry);
    }
    ui_print_footer(list);
}
