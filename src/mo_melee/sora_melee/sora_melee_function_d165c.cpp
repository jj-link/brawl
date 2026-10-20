#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    char pad[8];
    u32 top : 8;
    u32 rest : 24;
};

extern "C" void fn_27_D165C(FnObj *p, u32 v) {
    p->top = v;
}
