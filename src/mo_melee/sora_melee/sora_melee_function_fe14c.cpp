#pragma force_active on
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct FnDst {
    s32 a;
    s32 b;
    s16 c;
    s16 d;
};

extern "C" void fn_27_FE14C(FnDst* dst, s32* src, s32 val, s16* src2, s16 val2)
{
    src = (s32*)*src;
    s16 y = *src2;
    dst->a = (s32)src;
    dst->b = val;
    dst->c = y;
    dst->d = val2;
}
