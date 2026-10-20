#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_B8;
void* fn_27_4FAB4(void* manager);

void fn_27_380E8(void* self) {
    if (!lbl_27_bss_B8) {
        void* manager = operator new(0x1508, Heaps::System);
        if (manager) {
            manager = fn_27_4FAB4(manager);
        }
        lbl_27_bss_B8 = manager;
    }
    s16 idx = *(s16*)((u8*)self + 0x70);
    void* arr = *(void**)((u8*)lbl_27_bss_B8 + 0xa4);
    u8* elem = (u8*)arr + idx * 0x34;
    union {
        struct {
            unsigned low : 16;
            unsigned counter : 15;
            unsigned high : 1;
        };
        u32 raw;
    } u;
    u.raw = *(u32*)(elem + 0x28);
    u.counter--;
    *(u32*)(elem + 0x28) = u.raw;
}
}
