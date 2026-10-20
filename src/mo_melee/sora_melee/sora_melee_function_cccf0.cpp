#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct S {
    u32 pad[2];
    u32 f;
};

extern "C" s32 fn_27_CCCF0(S* p) {
    return (s32)((p->f << 3) & 0xF0000000) >> 29;
}
