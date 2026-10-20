#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FooObj {
    u32 pad0;
    u32 pad4;
    u32 field8;
};

extern "C" {
s32 fn_27_CBD34(struct FooObj* p) {
    u32 v = p->field8;
    return (s32)(((v << 10) | (v >> 22)) & 0xFC000000) >> 27;
}
}
