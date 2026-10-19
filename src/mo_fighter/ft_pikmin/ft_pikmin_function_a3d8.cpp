#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_F0;
void* fn_27_5BCD0(void* obj);

void* fn_113_A3D8() {
    if (!lbl_27_bss_F0) {
        void* obj = operator new(0x4C, Heaps::System);
        if (obj) {
            obj = fn_27_5BCD0(obj);
        }
        lbl_27_bss_F0 = obj;
    }
    return lbl_27_bss_F0;
}
}
