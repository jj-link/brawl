#include <types.h>
#pragma force_active on

extern "C" void* fn_111_7AA4(void* self, s32 n);

extern "C" void* fn_111_7B90(void* self, s32 n) {
    switch (n) {
    case 0:
        return self;
    case 1:
        return static_cast<u8*>(self) + 0x494;
    case 2:
        return fn_111_7AA4(self, n);
    default:
        return fn_111_7AA4(self, n);
    }
}
