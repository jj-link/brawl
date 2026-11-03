#include <types.h>
#pragma force_active on

extern void fn_80231A14(s32, u8 *, u16, u8);
extern void fn_80235AE8(void);
extern void fn_80235C5C(void);
extern void fn_80235D60(void);
extern void fn_80236CB4(void);
extern void fn_80237600(u8 *, u16, u8 *);
extern u8 fn_80237B54(u8 *);
extern u8 lbl_80529AC8[];
extern u8 lbl_805A0D30;
extern u8 lbl_80480434[];

s32 fn_80237954(u8 *arg0) {
    u8 var_r6 = 0x10;
    u8 *var_r31 = NULL;
    u16 temp_r0 = *(u16 *)arg0;

    switch (temp_r0) {
    case 0x170C:
        fn_80235AE8();
        break;
    case 0x170D:
        fn_80235C5C();
        break;
    case 0x170F:
        fn_80235D60();
        break;
    case 0x170E:
        fn_80236CB4();
        break;
    default:
        if (temp_r0 == 0x1700) {
            var_r6 = fn_80237B54(arg0 + 8);
        } else if (temp_r0 == 0x170A) {
            if (*(u16 *)(arg0 + 0x10) == 0xB) {
                var_r6 = fn_80237B54(arg0 + 8);
            } else {
                u8 *p = lbl_80529AC8 + *(u16 *)(arg0 + 6);
                var_r6 = p[0x214];
            }
        } else {
            u16 temp_r0_2 = *(u16 *)(arg0 + 6);
            if (temp_r0_2 < 0x10) {
                u8 *p = lbl_80529AC8 + temp_r0_2;
                var_r6 = p[0x214];
            }
        }
        if (var_r6 != 0x10) {
            u32 q = (u32)lbl_80529AC8 + (var_r6 << 5);
            var_r31 = (u8 *)(q + 0x10);
        }
        if (lbl_805A0D30 >= 5) {
            fn_80231A14(0x504, lbl_80480434, *(u16 *)(arg0 + 6), var_r6);
        }
        fn_80237600(var_r31, *(u16 *)arg0, arg0);
        break;
    }
    return 1;
}
