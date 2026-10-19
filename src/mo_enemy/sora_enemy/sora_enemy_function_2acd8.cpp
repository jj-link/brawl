#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_69EC0(void*, s8);

extern "C" {
s32 fn_41_2ACD8(void* self, s8 id) {
    s32 result = 0;
    if (fn_27_69EC0(self, id) == 1 || id == 0x6c) {
        result = 1;
    }
    return result;
}
}
