#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_8C064(u32, u32, u32);

extern "C" s32 fn_27_1DCAFC(u32 a, u32 b, s32 param)
{
    if (param <= 0x59D7)
        return fn_27_8C064(a, b, param);
    return 0;
}
