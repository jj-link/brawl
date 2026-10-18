#include <types.h>
#pragma force_active on

extern "C" int fn_27_A4950(void* self);
extern "C" u8 fn_27_A4340(void* self, u32 p2);
extern "C" u32* fn_27_A4964(void* self, int idx);

extern "C" bool fn_41_27688(void* self, u32 p2) {
    int count = fn_27_A4950(self);
    if (count <= 0) {
        return false;
    }
    if (fn_27_A4340(self, p2) != 0xD) {
        return false;
    }
    for (int i = 0; i < count; i++) {
        u32* p = fn_27_A4964(self, i);
        if (p2 == *p) {
            return true;
        }
    }
    return false;
}
