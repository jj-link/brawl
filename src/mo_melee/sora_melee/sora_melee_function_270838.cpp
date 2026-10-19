#include <types.h>
#pragma force_active on

extern "C" void __ct__10grYakumonoFPCc(void* self, const char* name);
extern "C" char lbl_27_data_57A20[];

extern "C" void* fn_27_270838(void* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(s32*)((char*)self + 0x17C) = 0;
    *(char**)((char*)self + 0x3C) = lbl_27_data_57A20;
    *(s32*)((char*)self + 0x180) = 0;
    return self;
}
