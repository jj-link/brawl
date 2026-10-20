#pragma force_active on
struct S { int a; int b; unsigned int pad:10; int v:5; };
extern "C" int fn_76_3D60(S* s) { return s->v; }
