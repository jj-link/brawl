#pragma force_active on
struct S { char pad[0x760]; int a; int pad2; int b; };
extern "C" void fn_54_E3F0(S* s, int a, int b) {
    s->a = a;
    s->b = b;
}
