#pragma force_active on
struct S { int a; int b; unsigned int x:4; unsigned int y:4; unsigned int z:24; };

extern "C" void fn_76_3FFC(S* s, int v) { s->y = v; }
