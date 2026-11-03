#include <string.h>
#pragma force_active on

extern unsigned char lbl_80529A98[];
extern unsigned char lbl_80529994[];
extern unsigned char *lbl_8059EDB0;
extern void fn_8023514C(void);
extern void fn_8023584C(void);
extern void fn_80232128(void (*)(void));
extern void fn_8023D8C0(int, void *, void (*)(void));

void fn_802350CC(void) {
    memset(lbl_80529A98, 0, 0x2E);
    if (lbl_8059EDB0[1] != 0) {
        fn_80232128(fn_8023514C);
        fn_8023D8C0(3, lbl_80529994 + 0x95, fn_8023584C);
    }
}
