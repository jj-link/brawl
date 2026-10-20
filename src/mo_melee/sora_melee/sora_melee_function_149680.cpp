#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_bss_3210[];

void* fn_27_149680(void);
}

void* fn_27_149680(void)
{
    return *(void**)(*(u8**)(lbl_27_bss_3210 + 0x78) + 0xac);
}
