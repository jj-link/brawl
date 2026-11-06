#pragma force_active on
#include <revolution/SI/SIHardware.h>

extern void OSRegisterVersion(const char *ver);
extern void fn_801DCF5C(int arg0, void *arg1);
extern void fn_801DD320(int arg0);
extern void fn_801E7204(int arg0);
extern void fn_801E74C8(int arg0);
extern void fn_801E6290(void);
extern int lbl_80474E98[];
extern int lbl_804DE330[];
extern const char *lbl_8059EA18;
extern int lbl_805A0784;

void fn_801E67DC(void) {
    if (lbl_805A0784 == 0) {
        int neg = -1;

        OSRegisterVersion(lbl_8059EA18);
        lbl_804DE330[24] = neg;
        lbl_804DE330[16] = neg;
        lbl_804DE330[8] = neg;
        lbl_804DE330[0] = neg;
        lbl_80474E98[1] = 0;
        fn_801E74C8(0);
        do {
        } while (SI_HW_REGS[SI_SICOMSCR] & 1);
        SI_HW_REGS[SI_SICOMSCR] = 0x80000000;
        fn_801DCF5C(0x14, fn_801E6290);
        fn_801DD320(0x800);
        fn_801E7204(0);
        fn_801E7204(1);
        fn_801E7204(2);
        fn_801E7204(3);
        lbl_805A0784 = 1;
    }
}
