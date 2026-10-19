#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_B8;
void* fn_27_4FAB4(void* manager);

void* fn_113_109E0() {
    if (!lbl_27_bss_B8) {
        void* manager = operator new(0x1508, Heaps::System);
        if (manager) {
            manager = fn_27_4FAB4(manager);
        }
        lbl_27_bss_B8 = manager;
    }
    return lbl_27_bss_B8;
}
}
