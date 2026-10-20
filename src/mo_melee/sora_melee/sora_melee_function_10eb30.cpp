#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;
typedef short s16;

struct FnDst {
    u32 a;
    s32 b;
    s16 c;
    s16 d;
};

extern "C" {
void fn_27_10EB30(FnDst* dst, u32* src, s32 b, s16* hsrc, s16 d)
{
    s16 h;
    src = (u32*)*src;
    h = *hsrc;
    dst->a = (u32)src;
    dst->b = b;
    dst->c = h;
    dst->d = d;
}
}
