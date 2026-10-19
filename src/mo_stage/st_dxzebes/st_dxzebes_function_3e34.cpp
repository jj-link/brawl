#pragma force_active on
struct S { char pad[0x188]; int a; float b; };
extern "C" void fn_84_3E34(S* s, int* o1, float* o2) {
    *o1 = s->a;
    *o2 = s->b;
}
