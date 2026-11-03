#include <types.h>
#pragma force_active on

extern void fn_801D76BC(void *, u32);
extern void fn_801DE964(void (*)(void));
extern int fn_801DE368(void);
extern void fn_801DE914(void);
extern void fn_801DE41C(void);
extern void fn_801DE49C(void);
extern void fn_801DE51C(void);
extern void fn_801DE5FC(void);
extern void fn_801DE6DC(void);
extern void fn_801DE788(void);
extern void fn_801DE868(void);

void fn_801DE97C(void) {
    u32 temp_r31;
    u32 temp_r3;
    u32 temp_r4;

    if (*(s32 *)0x80003138 == 0 && &fn_801DE368 == 0) {
        fn_801DE964(fn_801DE914);
        return;
    }
    temp_r31 = *(u32 *)0x80003104;
    if (temp_r31 < *(u32 *)0x80003100 && temp_r31 == 0x01800000) {
        fn_801D76BC((void *)0x81800000, 0x01800000);
        *(s16 *)0xCC004028 = 2;
    }
    if (temp_r31 <= 0x01800000) {
        fn_801DE964(fn_801DE41C);
    } else if (temp_r31 <= 0x03000000) {
        fn_801DE964(fn_801DE49C);
    }
    temp_r4 = *(u32 *)0x8000311C;
    temp_r3 = *(u32 *)0x80003120;
    if (temp_r4 <= 0x04000000) {
        if (temp_r3 <= 0x93400000) {
            fn_801DE964(fn_801DE51C);
            return;
        }
        if (temp_r3 <= 0x93800000) {
            fn_801DE964(fn_801DE5FC);
            return;
        }
        fn_801DE964(fn_801DE6DC);
        return;
    }
    if (temp_r4 <= 0x08000000) {
        if (temp_r3 <= 0x97000000) {
            fn_801DE964(fn_801DE788);
            return;
        }
        fn_801DE964(fn_801DE868);
    }
}
