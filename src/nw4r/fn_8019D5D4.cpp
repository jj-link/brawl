#include <types.h>
#pragma force_active on
extern "C" void* fn_801970EC(u8* p);

extern "C" int fn_8019D5D4(u8* self) {
    u8* inner = (u8*)fn_801970EC(self + 0x20);
    int result = 0;
    if (inner != 0 && (*(u32*)(inner + 0x1C) & 8)) {
        result = 1;
    }
    return result;
}
