#include <string.h>
#pragma force_active on

extern "C" void* __ct__10grYakumonoFPCc(void*, const char*);
extern "C" char lbl_60_data_840[];

extern "C" void* fn_60_6424(void* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3C) = lbl_60_data_840;
    memset((char*)self + 0x150, 0, 0x80);
    return self;
}
