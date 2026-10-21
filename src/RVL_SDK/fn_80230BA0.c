#include <types.h>
#pragma force_active on

extern unsigned char lbl_80525F28[0x38];

extern void fn_80231754(void*);
extern void fn_80231800(void);

void fn_80230BA0() {
    lbl_80525F28[0x1E] = 0;
    fn_80231754(lbl_80525F28);
    fn_80231800();
}
