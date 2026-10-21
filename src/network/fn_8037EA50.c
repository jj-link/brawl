#include <types.h>
#pragma force_active on

extern void fn_8037BE6C(void);
extern void fn_8037BE74(void);
extern void fn_8037BE78(void);
extern s32 lbl_8059FA50;
extern s32 lbl_8059FA54;
extern s32 lbl_805A1078;

void fn_8037EA50(void) {
    fn_8037BE74();
    if (++lbl_805A1078 == 1) {
        fn_8037BE6C();
        lbl_8059FA50 = 0x7d;
        lbl_8059FA54 = 0xfa;
    } else {
        fn_8037BE78();
    }
}
