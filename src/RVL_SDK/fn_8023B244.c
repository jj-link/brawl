#include <types.h>
#pragma force_active on

extern char lbl_80529CF8[];
extern void fn_80232020(void *);

void fn_8023B244(u8 *arg0) {
    void (*func)(void *);
    func = *(void (**)(void *))(lbl_80529CF8 + 0x5A8);
    fn_80232020(lbl_80529CF8 + 0x590);
    *(void (**)(void *))(lbl_80529CF8 + 0x5A8) = NULL;
    if (func != NULL) {
        if (*arg0 == 0) {
            func(arg0 + 1);
        }
        else {
            func(NULL);
        }
    }
}
