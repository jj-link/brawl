#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    char pad[8];
    u32 mode : 3;
    u32 rest : 29;
};

extern "C" {
void fn_27_CC6C8(FnObj* p, u32 v) {
    p->mode = v;
}
}
