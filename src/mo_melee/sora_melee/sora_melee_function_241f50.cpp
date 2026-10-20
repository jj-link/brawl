#include <types.h>
#pragma force_active on

extern "C" void fn_27_241E30(void* self, const char* name);
extern "C" char lbl_27_data_4E0C0[];
extern "C" char lbl_27_data_4E0D0[];

extern "C" void* fn_27_241F50(void* self) {
    char* p = (char*)self;
    fn_27_241E30(self, lbl_27_data_4E0C0);
    *(char**)(p + 0x3c) = lbl_27_data_4E0D0;
    *(u8*)(p + 0x4c) = 0;
    *(s32*)(p + 0x50) = -1;
    *(u8*)(p + 0x54) = 0;
    *(s32*)(p + 0x58) = 0x3c;
    *(u8*)(p + 0x5c) = 0;
    *(u8*)(p + 0x5d) = 0;
    *(u8*)(p + 0x5e) = 0;
    *(s32*)(p + 0x60) = 0;
    *(u8*)(p + 0x40) = 0;
    return self;
}
