#pragma force_active on
typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

#pragma use_lmw_stmw on

extern "C" void fn_802CC4EC(void *, void *, s32, s32, s32, s32, s32, s32, s32);

extern "C" void fn_802CC0EC(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 n;
    u8 *temp;
    s32 zero;

    zero = 0;
    n = *(s32 *)(arg0 + 0x18C);
    temp = arg0 + n * 0x14;
    *(s32 *)(temp + 0x990) = *(s32 *)(arg1 + 0x0);
    *(s32 *)(temp + 0x994) = *(s32 *)(arg1 + 0x4);
    *(s32 *)(temp + 0x998) = *(s32 *)(arg1 + 0x8);
    *(s32 *)(temp + 0x99C) = *(s32 *)(arg1 + 0xC);
    *(u8 *)(temp + 0x9A0) = *(u8 *)(arg1 + 0x10);
    *(u8 *)(temp + 0x9A1) = *(u8 *)(arg1 + 0x11);
    fn_802CC4EC(arg0, arg0 + 0xE94, 1, arg2, arg3, arg2, arg3, *(s32 *)(arg0 + 0x1C2C), zero);
    fn_802CC4EC(arg0, arg0 + 0x190, *(s32 *)(arg0 + 0x18C), arg2, arg3, arg2, arg3, *(s32 *)(arg0 + 0x1C24), zero);
    if (*(s8 *)(arg1 + 0x11) != 0) {
        fn_802CC4EC(arg0, arg0 + 0x1294, 1, arg2, arg3, arg2, arg3, *(s32 *)(arg0 + 0x1C30), zero);
        fn_802CC4EC(arg0, arg0 + 0x590, *(s32 *)(arg0 + 0x18C), arg2, arg3, arg2, arg3, *(s32 *)(arg0 + 0x1C28), zero);
    }
    *(s32 *)(arg0 + 0x18C) = *(s32 *)(arg0 + 0x18C) + 1;
}
