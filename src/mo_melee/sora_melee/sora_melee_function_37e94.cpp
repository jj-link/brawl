#include <sr/sr_common.h>
#pragma force_active on
extern "C" {
extern void* lbl_27_bss_B8;
void fn_27_37D7C(void*, void*, int, int);
void* fn_27_4FAB4(void*);
unsigned int fn_27_501A4(void*, short, void*);
void fn_27_37E94(char* p, short index) {
    fn_27_37D7C(p, p + 0x28, 1, 0);
    fn_27_37D7C(p, p, 1, 0);
    fn_27_37D7C(p, p + 0xc, 1, 0);
    if (!lbl_27_bss_B8) {
        void* manager = operator new(0x1508, Heaps::System);
        if (manager) manager = fn_27_4FAB4(manager);
        lbl_27_bss_B8 = manager;
    }
    p[0x72] = fn_27_501A4(lbl_27_bss_B8, index, p + 0x18);
    if (!lbl_27_bss_B8) {
        void* manager = operator new(0x1508, Heaps::System);
        if (manager) manager = fn_27_4FAB4(manager);
        lbl_27_bss_B8 = manager;
    }
    char* entry = *(char**)((char*)lbl_27_bss_B8 + 0xa4) + index * 0x34;
    *(short*)(p + 0x70) = index;
    *(char**)(p + 0x34) = entry;
    *(char**)(p + 0x38) = entry + 0xc;
    *(char**)(p + 0x3c) = entry + 0x18;
}
}