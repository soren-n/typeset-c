#pragma once

#include <stdint.h>

/*
  Arena
*/
typedef struct typeset_arena typeset_arena;

typeset_arena* typeset_alloc_arena();
void typeset_free_arena(typeset_arena* arena);

/*
  Layout
*/
typedef struct typeset_layout typeset_layout;

typeset_layout* typeset_make_null(
  typeset_arena* arena
);

typeset_layout* typeset_make_text(
  typeset_arena* arena,
  const char* data,
  uint32_t length
);

typeset_layout* typeset_make_fix(
  typeset_arena* arena,
  typeset_layout* layout
);

typeset_layout* typeset_make_grp(
  typeset_arena* arena,
  typeset_layout* layout
);

typeset_layout* typeset_make_seq(
  typeset_arena* arena,
  typeset_layout* layout
);

typeset_layout* typeset_make_nest(
  typeset_arena* arena,
  typeset_layout* layout
);

typeset_layout* typeset_make_pack(
  typeset_arena* arena,
  typeset_layout* layout
);

typeset_layout* typeset_make_line(
  typeset_arena* arena,
  typeset_layout* left,
  typeset_layout* right
);

typeset_layout* typeset_make_comp(
  typeset_arena* arena,
  typeset_layout* left,
  typeset_layout* right
);

/*
  Document
*/
typedef struct typeset_document typeset_document;

typeset_document* typeset_compile(
  typeset_arena* arena,
  typeset_layout* layout
);

uint32_t typeset_max_length(typeset_document* document);

uint32_t typeset_render(
  char* output_buffer,
  uint32_t indentation_width,
  uint32_t layout_buffer_width,
  typeset_document* document
);
