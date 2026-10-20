#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1B1AF0_arg {
    u32 pad[2];
    u32 flags;
};

extern "C" {
s32 fn_27_1B1AF0(fn_27_1B1AF0_arg* p) {
    u32 v = p->flags;
    s32 r = (s32)(((v >> 22) & 0xF) << 28);
    return r >> 29;
}
}
