#pragma force_active on
struct S { int a; int b; int c : 4; };
extern "C" int fn_79_5C4C(S* s) { return s->c; }
