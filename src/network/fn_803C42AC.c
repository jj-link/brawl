#include <types.h>
#pragma force_active on

extern u32 lbl_805A1210;
extern u32 lbl_805A1220;

void* fn_803C42AC(u32 arg0) {
    if (arg0 < lbl_805A1210 && lbl_805A1220 != 0) {
        return (void*)(lbl_805A1220 + arg0 * 0x140);
    }
    return 0;
}
