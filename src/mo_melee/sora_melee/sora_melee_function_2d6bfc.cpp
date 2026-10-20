#pragma force_active on
typedef int s32;

struct S {
    char pad0[0xc];
    s32 divisor;
    char pad1[0x24];
    s32 rem;
    s32 quot;
};

extern "C" void fn_27_2D6BFC(S* p, s32 a) {
    s32 q = a / p->divisor;
    p->quot = q;
    p->rem = a - q * p->divisor;
}
