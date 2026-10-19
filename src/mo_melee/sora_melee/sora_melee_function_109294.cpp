#include <types.h>
#pragma force_active on

extern s32 lbl_27_bss_1B18;

extern "C" void fn_27_109294(void* self, s32 val)
{
    switch (val) {
    case 0:
        lbl_27_bss_1B18 = 0;
        break;
    case 1:
        lbl_27_bss_1B18 = 1;
        break;
    }
    *((u8*)self + 0x69) = (u8)val;
}
