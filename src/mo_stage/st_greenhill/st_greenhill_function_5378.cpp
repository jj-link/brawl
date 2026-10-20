#pragma force_active on
struct S { int a; int b; int c; };
extern "C" int fn_72_5378(S* s) { return s->c >> 28; }
