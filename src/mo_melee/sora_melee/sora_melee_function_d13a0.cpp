#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct S {
    u32 pad[2];
    u32 val;
};

extern "C" s32 fn_27_D13A0(S* p) {
    u32 x = p->val;
    return (s32)((x << 16) & 0xFF800000) >> 24;
}
