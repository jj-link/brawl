#pragma force_active on
typedef unsigned int u32;
struct S { u32 a, b, c, d, e; };
extern "C" void fn_120_13D28(S* s, u32 v) {
    s->e = v;
    s->d = v;
    s->c = v;
}
