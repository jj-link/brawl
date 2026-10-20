#include <types.h>
#pragma force_active on

extern "C" char* lbl_27_bss_5668;

extern "C" {
int fn_27_2528DC(char* self) {
    int v = *(int*)(self + 0x270);
    if (v != 0 && v <= *(int*)(self + 0x284)) {
        return 1;
    }
    char* p = lbl_27_bss_5668;
    if (p != 0 && *(int*)(p + 0x44) == 0x38) {
        int r = (*(int*)(p + 0x358) == 0);
        *(u8*)(self + 0x288) = r;
        return r;
    }
    return 0;
}
}
