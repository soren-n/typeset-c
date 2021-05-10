#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "arena.h"

/*
  Layout
*/
typedef struct typeset_layout typeset_layout;

typeset_layout* typeset_make_null(
  typeset_arena* arena
);

typeset_layout* typeset_make_text(
  typeset_arena* arena,
  const char* content,
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
  typeset_layout* right,
  bool pad,
  bool fix
);
