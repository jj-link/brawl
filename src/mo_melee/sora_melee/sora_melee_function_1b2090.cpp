#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct S27 {
    u32 pad[2];
    u32 v;
};

extern "C" {
s32 fn_27_1B2090(S27* p) {
    return (s32)((p->v << 8) & 0xF8000000) >> 28;
}
}
