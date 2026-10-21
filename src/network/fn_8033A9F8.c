#include <revolution/types.h>
#pragma force_active on

extern void *lbl_805A0F88;

s32 DWC_GetState(void) {
    void *p = lbl_805A0F88;
    if (p != NULL) {
        return *(s32 *)((char *)p + 0x24);
    }
    return 0;
}
