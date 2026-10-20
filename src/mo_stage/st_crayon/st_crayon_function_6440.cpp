#pragma force_active on
struct Obj { int a; int b; unsigned int flags; };
extern "C" void fn_56_6440(Obj* o) { o->flags |= 0x2000000; }
