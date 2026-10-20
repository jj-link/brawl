#pragma force_active on
struct S { int pad[2]; unsigned int a:5; unsigned int b:5; unsigned int c:22; };
extern "C" void fn_76_3D0C(S* s, unsigned int v) { s->b = v; }
