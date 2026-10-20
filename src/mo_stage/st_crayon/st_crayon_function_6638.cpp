#pragma force_active on
struct S { int a; int b; unsigned int flags; };
extern "C" void fn_56_6638(S* s) { s->flags |= 0x2000000; }
