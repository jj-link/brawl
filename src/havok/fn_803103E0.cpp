#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void fn_8031041C(s32, s32, s32, u8 *);

extern "C" void fn_803103E0(s32 arg0, s32 arg1, u8 *arg2)
{
    u8 sp8;

    if (arg1 > 1) {
        sp8 = *arg2;
        fn_8031041C(arg0, 0, arg1 - 1, &sp8);
    }
}
