#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern s32 fn_8020CAD4(void);
extern s32 fn_8020CAEC(void);
extern s32 fn_802152E4(s32, void (*)(s32, void *), void *);
extern void fn_8020C670(s32, void *);

s32 fn_8020BCA8(u8 *arg0, s32 arg1, u8 *arg2) {
    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    if (arg0[0x8A] != 1) {
        return -8;
    }
    *(s32 *)(arg2 + 0x4) = arg1;
    *(u8 **)(arg2 + 0x8) = arg0;
    fn_802152E4(*(s32 *)arg0, fn_8020C670, arg2);
    return fn_8020CAEC();
}
