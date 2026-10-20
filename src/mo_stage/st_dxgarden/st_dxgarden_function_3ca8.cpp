#pragma force_active on
struct S { int a; int b; unsigned flags; };
extern "C" void fn_77_3CA8(S* s) {
    s->flags |= 0x2000000;
}
