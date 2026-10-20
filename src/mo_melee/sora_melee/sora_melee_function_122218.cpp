#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_122218(u8* self, s32 a, u32 b) {
    if (a == 0xc) {
        if (b == 0xc) {
            return *(u32*)(self + 0x340);
        }
        if (b == 0xd) {
            return *(u32*)(self + 0x33c);
        }
        if (b & 0x80) {
            return *(u32*)(self + 0x344);
        }
        return *(u32*)(self + ((b & 0xff) << 2) + 0x30c);
    }
    return *(u32*)(self + (a << 2) + 0x230);
}
