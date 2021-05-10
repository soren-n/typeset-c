# pragma once

#include <stddef.h>

/*
  Arena
*/
typedef struct typeset_arena typeset_arena;

typeset_arena* typeset_alloc_arena();
void typeset_scrub_arena(typeset_arena* arena);
void typeset_free_arena(typeset_arena* arena);
void* typeset_arena_alloc(typeset_arena* arena, size_t size);
