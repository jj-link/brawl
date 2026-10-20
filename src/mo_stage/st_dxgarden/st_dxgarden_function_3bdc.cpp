#pragma force_active on
struct S { int a; int b; unsigned f0:2; unsigned f1:2; unsigned rest:28; };
extern "C" void fn_77_3BDC(S* s, unsigned v) { s->f1 = v; }
