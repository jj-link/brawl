#include <types.h>
#pragma force_active on

extern "C" {
    extern char lbl_804882F0[];

    void fn_802E9890(void* arg0) {
        if (arg0 != NULL) {
            *(u16*)((u8*)arg0 + 6) = 1;
            *(void**)arg0 = &lbl_804882F0;
        }
    }
}
