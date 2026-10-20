#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct S {
    u32 pad[2];
    u32 field;
};

extern "C" s32 fn_27_1A260C(S* p) {
    return (s32)((p->field << 10) & 0xFC000000) >> 27;
}
