#pragma once

#include <stdint.h>

#include "arena.h"
#include "layout.h"

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
