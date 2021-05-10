#include <stddef.h>
#include <stdbool.h>

#include "typeset.h"

/*
  Arena
*/

struct typeset_arena {
  //
};

typeset_arena* typeset_alloc_arena() {
  return NULL;
}

void typeset_free_arena(typeset_arena* arena) {
  //
}

/*
  Layout
*/

enum layout_kind {
  LayoutKindNull,
  LayoutKindText,
  LayoutKindFix,
  LayoutKindGrp,
  LayoutKindSeq,
  LayoutKindNest,
  LayoutKindPack,
  LayoutKindLine,
  LayoutKindComp
};
typedef enum layout_kind layout_kind;

struct typeset_layout {
  layout_kind kind;
};

struct typeset_layout_null {
  typeset_layout base;
};

struct typeset_layout_text {
  typeset_layout base;
  char* content;
  uint32_t length;
};

struct typeset_layout_fix {
  typeset_layout base;
  typeset_layout* layout;
};

struct typeset_layout_grp {
  typeset_layout base;
  typeset_layout* layout;
};

struct typeset_layout_seq {
  typeset_layout base;
  typeset_layout* layout;
};

struct typeset_layout_nest {
  typeset_layout base;
  typeset_layout* layout;
};

struct typeset_layout_pack {
  typeset_layout base;
  typeset_layout* layout;
};

struct typeset_layout_line {
  typeset_layout base;
  typeset_layout* left;
  typeset_layout* right;
};

struct typeset_layout_comp {
  typeset_layout base;
  typeset_layout* left;
  typeset_layout* right;
  bool pad;
  bool fix;
};

typeset_layout* typeset_make_null(
  typeset_arena* arena
) {
  return NULL;
}

typeset_layout* typeset_make_text(
  typeset_arena* arena,
  const char* data,
  uint32_t length
) {
  return NULL;
}

typeset_layout* typeset_make_fix(
  typeset_arena* arena,
  typeset_layout* layout
) {
  return NULL;
}

typeset_layout* typeset_make_grp(
  typeset_arena* arena,
  typeset_layout* layout
) {
  return NULL;
}

typeset_layout* typeset_make_seq(
  typeset_arena* arena,
  typeset_layout* layout
) {
  return NULL;
}

typeset_layout* typeset_make_nest(
  typeset_arena* arena,
  typeset_layout* layout
) {
  return NULL;
}

typeset_layout* typeset_make_pack(
  typeset_arena* arena,
  typeset_layout* layout
) {
  return NULL;
}

typeset_layout* typeset_make_line(
  typeset_arena* arena,
  typeset_layout* left,
  typeset_layout* right
) {
  return NULL;
}

typeset_layout* typeset_make_comp(
  typeset_arena* arena,
  typeset_layout* left,
  typeset_layout* right
) {
  return NULL;
}

/*
  Fixed
*/

enum fixed_kind {
  DocumentFixedKindText,
  DocumentFixedKindComp
};
typedef enum fixed_kind fixed_kind;

struct typeset_fixed {
  fixed_kind kind;
};
typedef struct typeset_fixed typeset_fixed;

struct typeset_fixed_text {
  typeset_fixed base;
  char* content;
  uint32_t length;
};

struct typeset_fixed_comp {
  typeset_fixed base;
  typeset_fixed* left;
  typeset_fixed* right;
  bool pad;
};

/*
  Object
*/

enum object_kind {
  DocumentObjectKindText,
  DocumentObjectKindFix,
  DocumentObjectKindGrp,
  DocumentObjectKindSeq,
  DocumentObjectKindNest,
  DocumentObjectKindPack,
  DocumentObjectKindComp
};
typedef enum object_kind object_kind;

struct typeset_object {
  object_kind kind;
};
typedef struct typeset_object typeset_object;

struct typeset_object_text {
  typeset_object base;
  char* content;
  uint32_t length;
};

struct typeset_object_fix {
  typeset_object base;
  typeset_fixed* fixed;
};

struct typeset_object_grp {
  typeset_object base;
  typeset_object* object;
};

struct typeset_object_seq {
  typeset_object base;
  typeset_object* object;
};

struct typeset_object_nest {
  typeset_object base;
  typeset_object* object;
};

struct typeset_object_pack {
  typeset_object base;
  typeset_object* object;
};

struct typeset_object_comp {
  typeset_object base;
  typeset_object* left;
  typeset_object* right;
  bool pad;
};

/*
  Document
*/

enum document_kind {
  DocumentKindEOD,
  DocumentKindEmpty,
  DocumentKindBreak,
  DocumentKindLine
};
typedef enum document_kind document_kind;

struct typeset_document {
  document_kind kind;
};

struct typeset_document_eod {
  typeset_document base;
};

struct typeset_document_empty {
  typeset_document base;
  typeset_document* document;
};

struct typeset_document_break {
  typeset_document base;
  typeset_object* object;
  typeset_document* document;
};

struct typeset_document_line {
  typeset_document base;
  typeset_object* object;
};

typeset_document* typeset_compile(
  typeset_arena* arena,
  typeset_layout* layout
) {
  return NULL;
}

uint32_t typeset_max_length(typeset_document* document) {
  return 0;
}

uint32_t typeset_render(
  char* output_buffer,
  uint32_t indentation_width,
  uint32_t layout_buffer_width,
  typeset_document* document
) {
  return 0;
}
