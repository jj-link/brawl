#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern char lbl_80529CF8[];
extern char lbl_80480E78[];
void fn_802319FC(s32, void *, s32);
void *fn_8022EFF8(s32, void *);
void fn_802463DC(void *, s32);

s32 fn_8023B694(s32 arg0) {
    if ((u8)lbl_80529CF8[0x27C0] >= 4) {
        fn_802319FC(0xD0003, lbl_80480E78, arg0);
    }
    *(s16 *)(lbl_80529CF8 + 0x64C) = (s16)((arg0 * 0x271) / 1000);
    {
        void *p = fn_8022EFF8(2, lbl_80529CF8);
        if (p != 0) {
            fn_802463DC(p, arg0);
            return 0;
        }
    }
    return 3;
}
