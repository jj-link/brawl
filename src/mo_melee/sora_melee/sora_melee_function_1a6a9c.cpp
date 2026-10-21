#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 rest : 30;
    u32 b : 1;
    u32 top : 1;
};

extern "C" void fn_27_1A6A9C(S* p) {
    p->b = 0;
}
