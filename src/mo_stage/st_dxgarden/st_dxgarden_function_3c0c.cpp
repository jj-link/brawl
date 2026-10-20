#pragma force_active on
struct S { int a; int b; unsigned f; };
extern "C" void fn_77_3C0C(S* p) { p->f &= ~0x2000000u; }
