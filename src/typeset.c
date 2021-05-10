#include <stddef.h>

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

void* _typeset_arena_alloc(size_t size) {
  return NULL;
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
typedef struct typeset_layout typeset_layout;

struct typeset_layout_null {
  typeset_layout base;
};
typedef struct typeset_layout_null typeset_layout_null;

struct typeset_layout_text {
  typeset_layout base;
  const char* content;
  uint32_t length;
};
typedef struct typeset_layout_text typeset_layout_text;

struct typeset_layout_fix {
  typeset_layout base;
  typeset_layout* layout;
};
typedef struct typeset_layout_fix typeset_layout_fix;

struct typeset_layout_grp {
  typeset_layout base;
  typeset_layout* layout;
};
typedef struct typeset_layout_grp typeset_layout_grp;

struct typeset_layout_seq {
  typeset_layout base;
  typeset_layout* layout;
};
typedef struct typeset_layout_seq typeset_layout_seq;

struct typeset_layout_nest {
  typeset_layout base;
  typeset_layout* layout;
};
typedef struct typeset_layout_nest typeset_layout_nest;

struct typeset_layout_pack {
  typeset_layout base;
  typeset_layout* layout;
};
typedef struct typeset_layout_pack typeset_layout_pack;

struct typeset_layout_line {
  typeset_layout base;
  typeset_layout* left;
  typeset_layout* right;
};
typedef struct typeset_layout_line typeset_layout_line;

struct typeset_layout_comp {
  typeset_layout base;
  typeset_layout* left;
  typeset_layout* right;
  bool pad;
  bool fix;
};
typedef struct typeset_layout_comp typeset_layout_comp;

typeset_layout* typeset_make_null(
  typeset_arena* arena
) {
  typeset_layout_null* result = (typeset_layout_null*)_typeset_arena_alloc(
    sizeof(typeset_layout_null)
  );
  result->base.kind = LayoutKindNull;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_text(
  typeset_arena* arena,
  const char* content,
  uint32_t length
) {
  typeset_layout_text* result = (typeset_layout_text*)_typeset_arena_alloc(
    sizeof(typeset_layout_text)
  );
  result->base.kind = LayoutKindText;
  result->content = content;
  result->length = length;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_fix(
  typeset_arena* arena,
  typeset_layout* layout
) {
  typeset_layout_fix* result = (typeset_layout_fix*)_typeset_arena_alloc(
    sizeof(typeset_layout_fix)
  );
  result->base.kind = LayoutKindFix;
  result->layout = layout;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_grp(
  typeset_arena* arena,
  typeset_layout* layout
) {
  typeset_layout_grp* result = (typeset_layout_grp*)_typeset_arena_alloc(
    sizeof(typeset_layout_grp)
  );
  result->base.kind = LayoutKindGrp;
  result->layout = layout;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_seq(
  typeset_arena* arena,
  typeset_layout* layout
) {
  typeset_layout_seq* result = (typeset_layout_seq*)_typeset_arena_alloc(
    sizeof(typeset_layout_seq)
  );
  result->base.kind = LayoutKindSeq;
  result->layout = layout;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_nest(
  typeset_arena* arena,
  typeset_layout* layout
) {
  typeset_layout_nest* result = (typeset_layout_nest*)_typeset_arena_alloc(
    sizeof(typeset_layout_nest)
  );
  result->base.kind = LayoutKindNest;
  result->layout = layout;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_pack(
  typeset_arena* arena,
  typeset_layout* layout
) {
  typeset_layout_pack* result = (typeset_layout_pack*)_typeset_arena_alloc(
    sizeof(typeset_layout_pack)
  );
  result->base.kind = LayoutKindPack;
  result->layout = layout;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_line(
  typeset_arena* arena,
  typeset_layout* left,
  typeset_layout* right
) {
  typeset_layout_line* result = (typeset_layout_line*)_typeset_arena_alloc(
    sizeof(typeset_layout_line)
  );
  result->base.kind = LayoutKindLine;
  result->left = left;
  result->right = right;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_comp(
  typeset_arena* arena,
  typeset_layout* left,
  typeset_layout* right,
  bool pad,
  bool fix
) {
  typeset_layout_comp* result = (typeset_layout_comp*)_typeset_arena_alloc(
    sizeof(typeset_layout_comp)
  );
  result->base.kind = LayoutKindComp;
  result->left = left;
  result->right = right;
  result->pad = pad;
  result->fix = fix;
  return (typeset_layout*)result;
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
  const char* content;
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
  const char* content;
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
