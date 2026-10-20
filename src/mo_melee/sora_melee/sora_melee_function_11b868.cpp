#pragma force_active on
typedef unsigned int u32;
typedef short s16;

struct FnDst {
    u32 a;
    u32 b;
    s16 c;
    s16 d;
};

extern "C" void fn_27_11B868(FnDst* dst, u32* src, u32 val, s16* hsrc, s16 hval) {
    src = (u32*)*src;
    s16 c = *hsrc;
    dst->a = (u32)src;
    dst->b = val;
    dst->c = c;
    dst->d = hval;
}
