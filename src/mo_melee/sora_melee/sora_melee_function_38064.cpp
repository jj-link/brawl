#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_B8;
void* fn_27_4FAB4(void* manager);

void fn_27_38064(void* param) {
    if (!lbl_27_bss_B8) {
        void* manager = operator new(0x1508, Heaps::System);
        if (manager) {
            manager = fn_27_4FAB4(manager);
        }
        lbl_27_bss_B8 = manager;
    }
    short idx = *(short*)((char*)param + 0x70);
    void* manager = lbl_27_bss_B8;
    void* array = *(void**)((char*)manager + 0xA4);
    char* elem = (char*)array + idx * 0x34;
    union {
        u32 val;
        struct {
            u32 a : 16;
            u32 b : 15;
            u32 c : 1;
        };
    } u;
    u.val = *(u32*)(elem + 0x28);
    u.b++;
    *(u32*)(elem + 0x28) = u.val;
}
}
