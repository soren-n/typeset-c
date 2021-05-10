#include <stddef.h>
#include <unistd.h>

#include <sys/mman.h>
#include <fcntl.h>

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
  typeset_page* curr_page;
};

typeset_page* _typeset_next_page(size_t page_size, typeset_page* page) {
  return (typeset_page*)(((size_t*)page) + page_size);
}

void* _typeset_page_offset(typeset_page* page, size_t offset) {
  return (void*)(((size_t*)page) + offset);
}

typeset_page* _typeset_alloc_pages(size_t page_size, uint32_t page_count) {
  size_t total_size = page_size * page_count;
  int fd = open("/dev/zero", O_RDWR);
  typeset_page* result =
    (typeset_page*)mmap(
      0, total_size,
      PROT_READ|PROT_WRITE,
      MAP_PRIVATE, fd, 0
    );
  close(fd);
  typeset_page* curr_page = result;
  while( page_count > 1) {
    typeset_page* next_page = _typeset_next_page(page_size, curr_page);
    curr_page->next_page = next_page;
    curr_page->remain = page_size - sizeof(typeset_page);
    curr_page = next_page;
    page_count = page_count - 1;
  }
  curr_page->next_page = NULL;
  curr_page->remain = page_size - sizeof(typeset_page);
  return result;
}

typeset_arena* typeset_alloc_arena() {
  size_t page_size = getpagesize();
  typeset_arena* result = (typeset_arena*)_typeset_alloc_pages(page_size, 2);
  result->base.remain = page_size - sizeof(typeset_arena);
  result->page_size = page_size;
  result->page_count = 2;
  result->curr_page = (typeset_page*)result;
  return result;
}

void typeset_scrub_arena(typeset_arena* arena) {
  uint32_t page_size = arena->page_size;
  typeset_page* curr_page = (typeset_page*)arena;
  curr_page->remain = page_size - sizeof(typeset_arena);
  arena->curr_page = curr_page;
  while( curr_page != NULL) {
    typeset_page* next_page = curr_page->next_page;
    curr_page->remain = page_size - sizeof(typeset_page);
    curr_page = next_page;
  }
}

void typeset_free_arena(typeset_arena* arena) {
  uint32_t page_size = arena->page_size;
  typeset_page* curr_page = (typeset_page*)arena;
  while( curr_page != NULL) {
    typeset_page* next_page = curr_page->next_page;
    munmap(curr_page, page_size);
    curr_page = next_page;
  }
}

void* typeset_arena_alloc(typeset_arena* arena, size_t size) {
  uint32_t page_size = arena->page_size;
  if( size > (page_size - sizeof(typeset_page))) return NULL;
  typeset_page* curr_page = arena->curr_page;
  uint32_t remain = curr_page->remain;
  if( size > remain) {
    // Does not fit
    typeset_page* next_page = curr_page->next_page;
    if( next_page != NULL) {
      // Fresh page waiting
      curr_page = next_page;
    } else {
      // Allocate fresh pages
      uint32_t page_count = arena->page_count;
      next_page = _typeset_alloc_pages(page_size, page_count);
      curr_page->next_page = next_page;
      arena->curr_page = next_page;
      arena->page_count = page_count * 2;
      curr_page = next_page;
    }
  }
  // Fits on current page
  void* result = _typeset_page_offset(curr_page, page_size - remain);
  curr_page->remain = remain - size;
  return result;
}
