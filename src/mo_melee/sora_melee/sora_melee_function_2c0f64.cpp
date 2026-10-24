#include <types.h>
#pragma force_active on

extern "C" bool fn_27_2C0F64(void* self, u32 id) {
    if (id >= 1U && id <= 0x5BU && (id & 1) == 1) {
        switch (id) {
        case 0x33:
        case 0x35:
        case 0x37:
        case 0x39:
        case 0x3B:
        case 0x43:
        case 0x45:
        case 0x47:
        case 0x51:
            return false;
        default:
            return true;
        }
    }
    return false;
}
