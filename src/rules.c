#include "corganizer.h"
#include <string.h>

typedef struct {
  const char *ext;
  const char *category;
} Rule;

static const Rule rules[] = {
    {".pdf", "Documents"}, {".doc", "Documents"}, {".docx", "Documents"}, {".txt", "Documents"},

    {".jpg", "Images"},    {".jpeg", "Images"},   {".png", "Images"},     {".gif", "Images"},

    {".c", "Code"},        {".h", "Code"},        {".cpp", "Code"},       {".py", "Code"},
    {".js", "Code"},       {".ts", "Code"},

    {".zip", "Archives"},  {".rar", "Archives"},  {".gz", "Archives"},    {".tar", "Archives"}};

const char *get_category(const char *ext) {
  size_t count;

  count = sizeof(rules) / sizeof(rules[0]);

  for (size_t i = 0; i < count; i++) {
    if (strcmp(ext, rules[i].ext) == 0)
      return rules[i].category;
  }
  return "Others";
}
