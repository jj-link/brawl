#include <types.h>
#pragma force_active on

extern "C" void fn_27_2556C(void*, void*, void*, void*, void*);
extern "C" void fn_27_311F8(void*);
extern "C" u8 lbl_27_bss_2AC[];
extern "C" u8 lbl_41_data_39C0[];

extern "C" void* fn_41_2B43C(void* self, void* a, void* b, void* c) {
    u8* p = (u8*)self;
    u8* base = lbl_41_data_39C0;
    fn_27_2556C(self, a, b, lbl_27_bss_2AC, p + 0x5c);
    *(u8**)(p + 0x08) = base;
    *(u8**)(p + 0x00) = base + 0x08;
    *(u8**)(p + 0x0c) = base + 0x270;
    *(u8**)(p + 0x18) = base + 0x280;
    *(u8**)(p + 0x24) = base + 0x294;
    *(void**)(p + 0x58) = c;
    fn_27_311F8(p + 0x5c);
    return self;
}
