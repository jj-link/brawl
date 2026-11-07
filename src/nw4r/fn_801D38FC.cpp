#include <types.h>
#pragma force_active on

extern "C" void fn_801BC4C0(void* self);
extern "C" void fn_801D3FD4(void* self);
extern "C" char lbl_80466D60[];

extern "C" void* fn_801D38FC(void* self, void* arg) {
    unsigned char* p = (unsigned char*)self;
    fn_801BC4C0(self);
    *(char**)p = lbl_80466D60;
    fn_801D3FD4(p + 0xD8);
    *(void**)(p + 0x1B4) = arg;
    *(int*)(p + 0x1B0) = 0;
    p[0x1B8] = 0;
    return self;
}