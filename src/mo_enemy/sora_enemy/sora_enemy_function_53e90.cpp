#include <types.h>
#pragma force_active on

extern "C" void* fn_41_53E90(u8* self, s32 idx)
{
    if (idx == 4) {
        return self + 0xCC;
    }
    if (idx == 3) {
        return self + 0xA0;
    }
    if (idx == 2) {
        return self + 0x74;
    }
    if (idx == 1) {
        return self + 0x48;
    }
    if (idx == 0) {
        return self + 0x1C;
    }
    return 0;
}
