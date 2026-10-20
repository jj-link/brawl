#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_bss_3210[];
}

extern "C" void* fn_27_147C60() {
    char* p = *(char**)(lbl_27_bss_3210 + 0x3c);
    return *(void**)(p + 0x138);
}
