#include <types.h>
#pragma force_active on
extern void fn_80232020(void *);
extern void fn_80258780(void *, void *, u16);
extern void fn_802588C8(void *, void *, u16);
extern void fn_80258B70(void *, void *, u16);
extern void fn_80231A14(u32, u8 *, u8, u8);
extern void fn_80259FF4(void *, u16);
extern u8 lbl_8052D9C0[];
extern u8 lbl_80484C80[];

void fn_80258640(u8 *arg0, u8 *arg1) {
    u8 type;
    int invalid = 1;
    u8 *p;
    int len;
    fn_80232020(arg0 + 8);
    p = arg1 + *(u16 *)(arg1 + 4);
    type = p[8];
    len = *(u16 *)(arg1 + 2) - 1;
    *(u16 *)(arg1 + 2) = len;
    switch (type) {
    case 3:
        if (arg0[0x474] == 1) {
            fn_80258780(arg0, p + 9, len);
            invalid = 0;
        }
        break;
    case 5:
        if (arg0[0x474] == 2) {
            fn_802588C8(arg0, p + 9, len);
            invalid = 0;
        }
        break;
    case 7:
        if (arg0[0x474] == 3) {
            fn_80258B70(arg0, p + 9, len);
            invalid = 0;
        }
        break;
    }
    if (invalid) {
        if (lbl_8052D9C0[0x4630] >= 2) {
            fn_80231A14(0xA0001, lbl_80484C80, type, arg0[0x474]);
        }
        fn_80259FF4(arg0, 0x10000 - 13);
    }
}