#pragma force_active on
struct S { char pad[0x184]; bool a; int b; float c; };
extern "C" void fn_69_254C(S* s, bool a, int b, float c) {
    s->a = a;
    s->b = b;
    s->c = c;
}
