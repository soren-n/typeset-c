#include <unistd.h>

#include "typeset.h"

/*
  Arena
*/

typedef struct typeset_page typeset_page;
struct typeset_page {
  typeset_page* next_page;
  size_t remain;
};

struct typeset_arena {
  typeset_page base;
  uint32_t page_size;
  uint32_t page_count;
  typeset_page* current_page;
};

typeset_arena* typeset_alloc_arena() {
  return NULL;
}

void typeset_scrub_arena(typeset_arena* arena) {
  //
}

void typeset_free_arena(typeset_arena* arena) {
  //
}

void* typeset_arena_alloc(typeset_arena* arena, size_t size) {
  return NULL;
}
