#include <revolution/GX/GXHardware.h>
#pragma force_active on
typedef unsigned long u32;
typedef struct {
    u32 a : 12;
    u32 b : 1;
    u32 c : 19;
} Reg254;
extern unsigned char* const __GXData;

void fn_801F1394(u32 arg0) {
    ((Reg254*)(__GXData + 0x254))->b = arg0;
    WGPIPE.uc = 0x61;
    WGPIPE.ui = 0xFE080000;
    WGPIPE.uc = 0x61;
    WGPIPE.ui = *(u32*)(__GXData + 0x254);
}
