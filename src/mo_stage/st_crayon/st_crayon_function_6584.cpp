#pragma force_active on
struct Obj { int a; int b; unsigned int flags; };
extern "C" void fn_56_6584(Obj* p) { p->flags |= 0x2000000; }
