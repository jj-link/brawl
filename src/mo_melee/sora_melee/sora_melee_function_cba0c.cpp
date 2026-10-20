#pragma force_active on
typedef unsigned int u32;

struct fn_27_CBA0C_obj {
    u32 pad0;
    u32 pad1;
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_CBA0C(fn_27_CBA0C_obj* p, u32 v) {
    p->hi = v;
}
