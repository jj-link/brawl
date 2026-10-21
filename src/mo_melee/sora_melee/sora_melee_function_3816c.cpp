#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_B8;
void* fn_27_4FAB4(void* manager);

int fn_27_3816C(void* self) {
    if (!lbl_27_bss_B8) {
        void* manager = operator new(0x1508, Heaps::System);
        if (manager) {
            manager = fn_27_4FAB4(manager);
        }
        lbl_27_bss_B8 = manager;
    }
    s32 idx = *(s16*)((u8*)self + 0x70);
    void* base = *(void**)((u8*)lbl_27_bss_B8 + 0xa4);
    u32 word = *(u32*)((u8*)base + idx * 0x34 + 0x28);
    return ((word >> 1) & 0x7FFF) != 0;
}
}
