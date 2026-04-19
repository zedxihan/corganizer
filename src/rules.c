#include "corganizer.h"

#include <stddef.h>
#include <strings.h>

typedef struct {
  const char *category;
  const char *extensions[64];
} RuleGroup;

static const RuleGroup rules[] = {
    {"Documents", {".pdf", ".doc", ".docx", ".txt", ".md", ".csv", ".xlsx", ".pptx", NULL}},
    {"Images", {".jpg", ".jpeg", ".png", ".gif", ".svg", ".webp", NULL}},
    {"Code",
     {".c", ".h", ".cpp", ".py", ".js", ".ts", ".jsx", ".tsx", ".html", ".css", ".json", ".sh",
      ".java", ".go", ".rb", ".php", ".rs", ".swift", NULL}},
    {"Archives", {".zip", ".rar", ".gz", ".tar", ".7z", ".xz", NULL}},
    {"Media", {".mp4", ".mp3", ".mkv", ".wav", ".avi", ".mov", ".flv", ".wmv", NULL}}};

const char *get_category(const char *ext) {
  size_t count = sizeof(rules) / sizeof(rules[0]);

  if (!ext || ext[0] == '\0')
    return "Others";

  for (size_t i = 0; i < count; i++) {
    for (size_t j = 0; rules[i].extensions[j] != NULL; j++) {
      if (strcasecmp(ext, rules[i].extensions[j]) == 0)
        return rules[i].category;
    }
  }
  return "Others";
}
