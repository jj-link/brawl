#include <types.h>
#pragma force_active on

extern "C" u8 fn_27_1141C4(u8* self, u32 key) {
    u8 count = self[8];
    u8 i;
    for (i = 0; i < count; i++) {
        u8* entry = *(u8**)(self + (i << 3) + 0x34);
        if (entry != 0 && key == *(u32*)(entry + 0x28)) {
            return i;
        }
    }
    return 0xff;
}
