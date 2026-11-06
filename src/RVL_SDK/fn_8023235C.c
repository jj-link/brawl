#include <string.h>
#pragma force_active on

extern unsigned char lbl_80529858[0x90];
extern unsigned char* lbl_8059EDD0;
extern unsigned char lbl_805A0D30;
extern void fn_802325A0(void* a, unsigned int b, unsigned char c);
extern int fn_80230500(void);

void fn_8023235C(void) {
    memset(lbl_80529858, 0, 0x8C);
    fn_802325A0(&lbl_80529858[0x68], 0x3E8, lbl_8059EDD0[3]);
    lbl_80529858[0x7D] = fn_80230500();
    lbl_805A0D30 = lbl_8059EDD0[4];
}
