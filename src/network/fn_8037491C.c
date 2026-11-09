#include <types.h>
#pragma force_active on
extern s32 fn_8035D774(s32);
extern s32 fn_803741A4(s32, void **, s32, u16);
extern s32 fn_8037424C(void *, s32, s32, s32);
extern s32 fn_80376DF4(s32);
extern void fn_803782F8(void *);
extern s32 fn_803786FC(s32);
extern void fn_80378748(s32);
extern s32 fn_803789AC(s32, s32 *, u16 *);
extern s32 fn_803A7AF4(s32);
typedef struct {
    u8 pad0[0x0C];
    s32 state;
    u8 pad10[0x08];
    s32 result;
    u8 pad1C[0x04];
    s32 value20;
    s32 refCount;
} NetObj;
s32 fn_8037491C(s32 arg0, void **arg1, s32 arg2, s32 arg3,
                s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    void *sp10;
    s32 spC;
    u16 sp8;
    s32 temp_r27;
    s32 temp_r3_2;
    if (fn_803789AC(arg2, &spC, &sp8) == 0 || spC == 0 || sp8 == 0) {
        return 4;
    }
    if (((u32)fn_803A7AF4(spC) & 0xE0000000U) == 0xE0000000U) {
        return 4;
    }
    temp_r3_2 = fn_803741A4(arg0, &sp10, spC, sp8);
    if (temp_r3_2 != 0) {
        return temp_r3_2;
    }
    ((NetObj *)sp10)->value20 = arg5;
    arg6 = fn_8037424C(sp10, arg3, arg4, arg6);
    if (arg6 != 0) {
        fn_803782F8(sp10);
        return arg6;
    }
    if (arg7 == 0) {
        if (arg1 != 0) {
            *arg1 = sp10;
        }
        return 0;
    }
    ((NetObj *)sp10)->refCount++;
    do {
        if (fn_80376DF4(arg0) != 0 && fn_803786FC(arg0) != 0) {
            fn_80378748(arg0);
        }
        temp_r27 = ((NetObj *)sp10)->state >= 5;
        if (temp_r27 == 0) {
            fn_8035D774(1);
        }
    } while (temp_r27 == 0);
    ((NetObj *)sp10)->refCount--;
    if (((NetObj *)sp10)->state == 5) {
        *arg1 = sp10;
    }
    return ((NetObj *)sp10)->result;
}