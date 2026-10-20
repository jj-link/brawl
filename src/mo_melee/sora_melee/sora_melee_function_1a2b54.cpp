#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A2B54_obj {
    char pad[8];
    u32 hi : 2;
    u32 rest : 30;
};

extern "C" {
void fn_27_1A2B54(fn_27_1A2B54_obj* p, u32 v) {
    p->hi = v;
}
}
