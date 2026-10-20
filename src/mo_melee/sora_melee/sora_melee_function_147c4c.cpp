#include <types.h>
#pragma force_active on

extern "C" char lbl_27_bss_3210[];

extern "C" {
void* fn_27_147C4C() {
    char* p = *(char**)(lbl_27_bss_3210 + 0x3c);
    return *(void**)(p + 0x134);
}
}
