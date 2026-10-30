#define _DEFAULT_SOURCE
#include "corganizer.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool scan_directory(const char *dir_path, FileList *list) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror(dir_path);
        return false;
    }

    list->count = 0;
    list->entries = calloc(MAX_FILES, sizeof(FileEntry));
    if (list->entries == NULL ||
        !arena_init(&list->string_arena, ARENA_CAPACITY)) {
        fprintf(stderr, "Out of memory\n");
        free(list->entries);
        closedir(dir);
        return false;
    }

    size_t prefix_len = strlen(dir_path) + 1; // "dir/"
    struct dirent *item;

    while ((item = readdir(dir)) != NULL) {
        if (item->d_type != DT_REG || item->d_name[0] == '.')
            continue;

        size_t size = prefix_len + strlen(item->d_name) + 1; // "dir/a.pdf\0"
        char *path = arena_alloc(&list->string_arena, size);
        if (list->count == MAX_FILES || !path) {
            fprintf(stderr, "Warning: too many files, ignoring the rest\n");
            break;
        }
        snprintf(path, size, "%s/%s", dir_path, item->d_name);

        FileEntry *entry = &list->entries[list->count++];
        entry->path = path;
        entry->name = path + prefix_len;
        entry->category = get_category(entry->name);
        entry->status = STATUS_PENDING;
    }
    closedir(dir);
    return true;
}

void list_release(FileList *list) {
    free(list->entries);
    arena_release(&list->string_arena);
}
