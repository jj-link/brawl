#include <types.h>
#pragma force_active on
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_801E000C(s32, u16);
extern s32 fn_801E5F64(s32);
extern s32 fn_801E6A4C(s32);
extern void fn_801E6BCC(u32);
extern s32 fn_801E6C38(s32, s32 *);
extern void fn_801E6DE8(s32, char *, int, unsigned char *, int, void (*)(void), u64);
extern s32 fn_801E7204(s32);
extern void fn_801E73B8(s32, void (*)(void));
extern void fn_80215C54(u32);
extern void *memset(void *, s32, u32);
extern void fn_8021565C(void);
extern void fn_80215B18(void);
extern u8 lbl_804F6760[];
extern s32 lbl_8059ECE4;
extern void (*lbl_8059ECF4)(s32, void *, s32 *);
extern char lbl_8059ECF8;
extern u32 lbl_805A0C2C, lbl_805A0C30, lbl_805A0C34, lbl_805A0C38, lbl_805A0C40, lbl_805A0C44;
s32 fn_80215FC4(s8 *obj) {
    s32 irq2;
    s32 sp8;
    u8 *cfg;
    u32 bit;
    s32 irq;
    s32 idx;
    s32 ret;
    irq = OSDisableInterrupts();
    cfg = lbl_804F6760;
    ret = 0;
    idx = 0;
    do {
        bit = 0x80000000U >> idx;
        if (lbl_805A0C30 & bit) {
            fn_80215C54(0);
            obj[0xA] = -2;
            memset(obj, 0, 0xA);
        } else if ((lbl_805A0C40 & bit) || lbl_8059ECE4 == idx) {
            obj[0xA] = -2;
            memset(obj, 0, 0xA);
        } else if (!(lbl_805A0C44 & bit)) {
            obj[0xA] = -1;
            memset(obj, 0, 0xA);
        } else if (fn_801E5F64(idx) != 0) {
            obj[0xA] = -3;
            memset(obj, 0, 0xA);
        } else if (fn_801E6A4C(idx) & 8) {
            fn_801E6C38(idx, &sp8);
            if (lbl_805A0C38 & bit) {
                obj[0xA] = 0;
                memset(obj, 0, 0xA);
                if (!(lbl_805A0C34 & bit)) {
                    lbl_805A0C34 |= bit;
                    fn_801E73B8(idx, fn_80215B18);
                }
            } else {
                u32 n9;
                u32 n8;
                u32 n7;
                u32 n6;
                u32 n5;
                irq2 = OSDisableInterrupts();
                fn_801E6BCC(bit);
                n9 = ~bit;
                n8 = lbl_805A0C44 & n9;
                n7 = lbl_805A0C38 & n9;
                n6 = lbl_805A0C34 & n9;
                n5 = lbl_805A0C30 & n9;
                lbl_805A0C44 = n8;
                lbl_805A0C38 = n7;
                lbl_805A0C34 = n6;
                lbl_805A0C30 = n5;
                lbl_805A0C2C &= n9;
                fn_801E000C(idx, 0);
                OSRestoreInterrupts(irq2);
                obj[0xA] = -1;
                memset(obj, 0, 0xA);
            }
        } else {
            if (!(fn_801E7204(idx) & 0x20000000)) {
                ret |= bit;
            }
            if (fn_801E6C38(idx, &sp8) == 0) {
                obj[0xA] = -3;
                memset(obj, 0, 0xA);
            } else if (sp8 & 0x80000000) {
                obj[0xA] = -3;
                memset(obj, 0, 0xA);
            } else {
                lbl_8059ECF4(idx, obj, &sp8);
                if (*(u16 *)obj & 0x2000) {
                    obj[0xA] = -3;
                    memset(obj, 0, 0xA);
                    fn_801E6DE8(idx, &lbl_8059ECF8, 1, cfg, 0xA, fn_8021565C, 0);
                } else {
                    obj[0xA] = 0;
                    *(u16 *)obj &= ~0x80;
                }
            }
        }
        idx += 1;
        cfg += 0xC;
        obj += 0xC;
    } while (idx < 4);
    OSRestoreInterrupts(irq);
    return ret;
}