#pragma force_active on
typedef int s32;

struct S {
    s32 pad[2];
    s32 v;
};

extern "C" s32 fn_27_1D5868(S* p) {
    return (s32)((p->v << 10) & 0xFC000000) >> 27;
}
