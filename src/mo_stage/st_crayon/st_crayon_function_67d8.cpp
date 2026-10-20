#pragma force_active on
struct S { int a; int b; unsigned int flags; };
extern "C" void fn_56_67D8(S* s) {
    s->flags &= ~0x80000;
}
