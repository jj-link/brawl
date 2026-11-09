#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern void fn_801D8690(const char *, int, const char *, ...);
extern s32 fn_801FA940(void *, s32, s32, s32, void (*)(void), s32);
extern void fn_801F67D8(void);
extern int lbl_8059EAD0;
extern char lbl_80476740[];

s32 fn_801F6708(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 total;

    if (arg3 < 0 || (u32)arg3 > *(u32 *)((char *)arg0 + 0x34)) {
        fn_801D8690((const char *)&lbl_8059EAD0, 0x337, lbl_80476740);
    }

    total = arg3 + arg2;
    if (total < 0 || (u32)total >= *(u32 *)((char *)arg0 + 0x34) + 0x20) {
        fn_801D8690((const char *)&lbl_8059EAD0, 0x33D, lbl_80476740);
    }

    *(s32 *)((char *)arg0 + 0x38) = arg4;
    fn_801FA940(arg0, arg1, arg2, *(s32 *)((char *)arg0 + 0x30) + (arg3 >> 2), fn_801F67D8, arg5);
    return 1;
}
