#include <types.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern s32 fn_8022BB2C(void);
extern s32 fn_8022D228(void);
extern s32 fn_8022BE54(void);
extern void fn_8022550C(void *p, ...);
extern void fn_8022B8BC(void (*a)(void), void (*b)(void));
extern void fn_8022B90C(s32 a);
extern void fn_8022BFD8(s32 a);
extern void fn_8022C090(s32 a, s32 b);
extern void fn_80234F34(void);
extern void fn_80216C90(void);
extern void fn_80216CC0(void);
extern void *memset(void *s, s32 c, u32 n);
extern char lbl_8047C6AC[];
extern OSAlarm lbl_804F67E0;
extern u8 lbl_804FBD58[];
extern s32 lbl_805A06E4;
extern u8 lbl_805A0C65;

s32 fn_80216CF0(s32 arg0, s32 arg1) {
    s32 ret;
    s32 state;
    u8 *p;
    s32 enabled;
    s32 i;

    ret = 0;
    state = fn_8022BB2C();
    if (arg0 == 0) {
        if (state == 3) {
            if (fn_8022D228() != 0) {
                fn_8022BE54();
                ret = 0;
            } else {
                switch (arg1) {
                case 0:
                    fn_8022550C(lbl_8047C6AC);
                    fn_8022B8BC(fn_80216C90, fn_80216CC0);
                    /* fallthrough */
                case 2:
                case 3:
                    enabled = OSDisableInterrupts();
                    if (lbl_805A0C65 != 0) {
                        OSRestoreInterrupts(enabled);
                    } else {
                        lbl_805A0C65 = 1;
                        fn_8022C090(0, 0);
                        i = 10;
                        p = lbl_804FBD58 + 0x2BD;
                        do {
                            memset(p, 0, 0x46);
                            i++;
                            p += 0x46;
                        } while (i < 14);
                        OSCancelAlarm(&lbl_804F67E0);
                        fn_8022BFD8(0);
                        fn_8022B90C(0);
                        OSRestoreInterrupts(enabled);
                    }
                    ret = 0;
                    break;
                case 5:
                    if (lbl_805A06E4 != 0) {
                        enabled = OSDisableInterrupts();
                        if (lbl_805A0C65 != 0) {
                            OSRestoreInterrupts(enabled);
                        } else {
                            lbl_805A0C65 = 1;
                            fn_8022C090(0, 0);
                            i = 10;
                            p = lbl_804FBD58 + 0x2BD;
                            do {
                                memset(p, 0, 0x46);
                                i++;
                                p += 0x46;
                            } while (i < 14);
                            OSCancelAlarm(&lbl_804F67E0);
                            fn_8022BFD8(0);
                            fn_8022B90C(0);
                            OSRestoreInterrupts(enabled);
                        }
                    } else {
                        arg1 = OSDisableInterrupts();
                        if (lbl_805A0C65 != 0) {
                            OSRestoreInterrupts(arg1);
                        } else {
                            lbl_805A0C65 = 1;
                            fn_80234F34();
                            OSCancelAlarm(&lbl_804F67E0);
                            fn_8022BFD8(0);
                            fn_8022B90C(1);
                            OSRestoreInterrupts(arg1);
                        }
                    }
                    ret = 0;
                    break;
                case 1:
                case 4:
                    p = (u8 *)OSDisableInterrupts();
                    if (lbl_805A0C65 != 0) {
                        OSRestoreInterrupts((s32)p);
                    } else {
                        lbl_805A0C65 = 1;
                        fn_80234F34();
                        OSCancelAlarm(&lbl_804F67E0);
                        fn_8022BFD8(0);
                        fn_8022B90C(1);
                        OSRestoreInterrupts((s32)p);
                    }
                    ret = 0;
                    break;
                case 6:
                    p = (u8 *)OSDisableInterrupts();
                    if (lbl_805A0C65 != 0) {
                        OSRestoreInterrupts((s32)p);
                    } else {
                        lbl_805A0C65 = 1;
                        fn_80234F34();
                        OSCancelAlarm(&lbl_804F67E0);
                        fn_8022BFD8(0);
                        fn_8022B90C(1);
                        OSRestoreInterrupts((s32)p);
                    }
                    ret = 0;
                    break;
                }
            }
        } else if (state == 5) {
            fn_8022BE54();
            ret = 0;
        } else if (state == 4 || (u32)(state - 1) <= 1) {
            ret = 0;
        } else if (state == 0) {
            ret = 1;
        }
    } else {
        ret = 1;
    }
    return ret;
}