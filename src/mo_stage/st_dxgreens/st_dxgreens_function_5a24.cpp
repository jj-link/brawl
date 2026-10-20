#pragma force_active on
struct S { int a; int b; int x:2; };
extern "C" int fn_79_5A24(S* s) { return s->x; }
