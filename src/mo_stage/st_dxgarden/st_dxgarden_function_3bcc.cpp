#pragma force_active on
struct S { int a; int b; int pad:2; int f:2; };
extern "C" int fn_77_3BCC(S* s) { return s->f; }
