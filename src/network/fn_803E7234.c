#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;

extern u16 fn_803D68CC(s32, s32);
extern s32 fn_803D6A50(s32, s32, s32, s32, s32);
extern void fn_803D6B68(s32, s32, u8 *);
extern void fn_803E9F5C(void);
extern void fn_803EA100(s8);
extern int lbl_8059FEE0;

void PFPATH_GetVolumeFromPath(s32 arg0)
{
    u8 sp8;

    if (fn_803D68CC(arg0, 1) >= 2U && fn_803D6A50(arg0, (s32)&lbl_8059FEE0, 1, 1, 1) == 0) {
        fn_803D6B68(arg0, 1, &sp8);
        fn_803EA100((s8)sp8);
    } else {
        fn_803E9F5C();
    }
}
