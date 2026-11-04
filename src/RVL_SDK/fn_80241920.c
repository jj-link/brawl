#include <string.h>
#pragma force_active on

extern unsigned char lbl_80529CF8[];
extern char lbl_80481C60[];
extern void fn_802319E4(unsigned int, const char *);
extern int fn_80245158(unsigned char *);

void fn_80241920(void) {
    unsigned char *p = lbl_80529CF8;
    if (p[0x27C0] >= 4U) {
        fn_802319E4(0xD0003, lbl_80481C60);
    }
    *(int *)(p + 0x194C) = 0;
    memset(lbl_80529CF8 + 0x1954, 0xFF, 6);
    fn_80245158(p + 0x27B4);
}