#include <types.h>
#pragma force_active on

extern "C" int fn_8004D97C(void* self, int index, u8 value) {
    u8* base = *reinterpret_cast<u8**>(static_cast<u8*>(self) + 0x28) + index * 0x124;
    if (*reinterpret_cast<u16*>(base + 0xe0) == 0) {
        return 0;
    }
    base[0xec] = value;
    return 1;
}
