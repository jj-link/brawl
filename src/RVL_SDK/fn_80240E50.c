#include <types.h>
#pragma force_active on

typedef void (*Cb3)(void *, u32, u32);

extern void *fn_8023A038(unsigned int);
extern void fn_80231A14(u32, const char *, s32, u32);
extern void fn_80231FB0(void *, s16, s32);
extern u8 fn_80241D40(void *);
extern void fn_8024223C(void);
extern char lbl_80481B38[];
extern char lbl_80529CF8[];

void fn_80240E50(unsigned int arg0, unsigned int arg1) {
    u8 *obj;
    u32 var;
    Cb3 cb3;
    u8 result;

    obj = (u8 *)fn_8023A038(arg0);
    if ((u8)lbl_80529CF8[0x27C0] >= 4) {
        if (obj != 0) {
            var = obj[0x7F];
        } else {
            var = 0;
        }
        fn_80231A14(0xD0003, lbl_80481B38, arg1, var);
    }
    if (obj != 0) {
        if (arg1 == 0x23) {
            *(void **)(lbl_80529CF8 + 0x1938) = obj;
            *(void **)(lbl_80529CF8 + 0x196C) = (void *)fn_8024223C;
            fn_80231FB0(lbl_80529CF8 + 0x195C, 0x16, 1);
            return;
        }
        if (arg1 != 0) {
            cb3 = *(Cb3 *)(obj + 4);
            if (cb3 != 0) {
                cb3(obj + 0x1C, *(u32 *)(obj + 8), 0xA);
                *(u32 *)(obj + 4) = 0;
            }
        } else {
            obj[0x76] = (u8)(obj[0x76] | 6);
            if (obj[0x7F] == 2) {
                obj[0x7F] = 0;
                result = fn_80241D40(obj);
                if (result != 1) {
                    cb3 = *(Cb3 *)(obj + 4);
                    if (cb3 != 0) {
                        cb3(obj + 0x1C, *(u32 *)(obj + 8), result);
                        *(u32 *)(obj + 4) = 0;
                    }
                }
            }
        }
    }
}