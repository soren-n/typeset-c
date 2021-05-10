#include "layout.h"

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
  typeset_layout_null* result =
    (typeset_layout_null*)typeset_arena_alloc(
      arena, sizeof(typeset_layout_null)
    );
  result->base.kind = LayoutKindNull;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_text(
  typeset_arena* arena,
  const char* content,
  uint32_t length
) {
  typeset_layout_text* result =
    (typeset_layout_text*)typeset_arena_alloc(
      arena, sizeof(typeset_layout_text)
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
  typeset_layout_fix* result =
    (typeset_layout_fix*)typeset_arena_alloc(
      arena, sizeof(typeset_layout_fix)
    );
  result->base.kind = LayoutKindFix;
  result->layout = layout;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_grp(
  typeset_arena* arena,
  typeset_layout* layout
) {
  typeset_layout_grp* result =
    (typeset_layout_grp*)typeset_arena_alloc(
      arena, sizeof(typeset_layout_grp)
    );
  result->base.kind = LayoutKindGrp;
  result->layout = layout;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_seq(
  typeset_arena* arena,
  typeset_layout* layout
) {
  typeset_layout_seq* result =
    (typeset_layout_seq*)typeset_arena_alloc(
      arena, sizeof(typeset_layout_seq)
    );
  result->base.kind = LayoutKindSeq;
  result->layout = layout;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_nest(
  typeset_arena* arena,
  typeset_layout* layout
) {
  typeset_layout_nest* result =
    (typeset_layout_nest*)typeset_arena_alloc(
      arena, sizeof(typeset_layout_nest)
    );
  result->base.kind = LayoutKindNest;
  result->layout = layout;
  return (typeset_layout*)result;
}

typeset_layout* typeset_make_pack(
  typeset_arena* arena,
  typeset_layout* layout
) {
  typeset_layout_pack* result =
    (typeset_layout_pack*)typeset_arena_alloc(
      arena, sizeof(typeset_layout_pack)
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
  typeset_layout_line* result =
    (typeset_layout_line*)typeset_arena_alloc(
      arena, sizeof(typeset_layout_line)
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
  typeset_layout_comp* result =
    (typeset_layout_comp*)typeset_arena_alloc(
      arena, sizeof(typeset_layout_comp)
    );
  result->base.kind = LayoutKindComp;
  result->left = left;
  result->right = right;
  result->pad = pad;
  result->fix = fix;
  return (typeset_layout*)result;
}
