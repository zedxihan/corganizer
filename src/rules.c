#include "corganizer.h"

#include <string.h>
#include <strings.h>

typedef struct {
    const char *category;
    const char *const *exts;
} RuleGroup;

// clang-format off
static const char *const document_exts[] = {".pdf", ".doc",  ".docx", ".txt",
                                            ".md",  ".csv",  ".xlsx", ".pptx", NULL};

static const char *const image_exts[] = {".jpg", ".jpeg", ".png", ".gif", ".svg", ".webp", NULL};

static const char *const code_exts[] = {".c",    ".h",   ".cpp",  ".py",  ".js",   ".ts",
                                        ".jsx",  ".tsx", ".html", ".css", ".json", ".sh",
                                        ".java", ".go",  ".rb",   ".php", ".rs",   ".swift", NULL};

static const char *const archive_exts[] = {".zip", ".rar", ".gz", ".tar", ".7z", ".xz", NULL};

static const char *const media_exts[] = {".mp4", ".mp3", ".mkv", ".wav",
                                         ".avi", ".mov", ".flv", ".wmv", NULL};

static const RuleGroup rules[] = {
    {"Documents", document_exts},
    {"Images", image_exts},
    {"Code", code_exts},
    {"Archives", archive_exts},
    {"Media", media_exts},
};
// clang-format on

const char *get_category(const char *filename) {
    const char *ext = strrchr(filename, '.');
    if (ext == NULL || ext == filename) // .bashrc
        return "Others";

    for (size_t i = 0; i < sizeof(rules) / sizeof(rules[0]); i++) {
        for (size_t j = 0; rules[i].exts[j] != NULL; j++) {
            if (strcasecmp(ext, rules[i].exts[j]) == 0)
                return rules[i].category;
        }
    }
    return "Others";
}
