#pragma force_active on
struct S { char pad[8]; unsigned int a; unsigned int b; unsigned int c; };
extern "C" void fn_122_18F4C(S* s, unsigned int v) {
    s->c = v;
    s->b = v;
    s->a = v;
}
