#pragma force_active on
typedef unsigned int u32;

struct fn_27_CFCDC_S {
    char pad[8];
    u32 hi : 7;
    u32 lo : 25;
};

extern "C" void fn_27_CFCDC(fn_27_CFCDC_S* p, u32 v) {
    p->hi = v;
}
