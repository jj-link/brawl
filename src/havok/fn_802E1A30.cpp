#include <types.h>
#pragma force_active on

extern "C" s32 fn_802E1A30(void* arg0) {
    void* ptr = *(void**)((char*)arg0 + 0x58);
    s32 val;
    if (ptr == NULL) {
        val = 0;
    } else {
        val = ((u8)((char*)ptr)[0x27] >> 6) & 3;
    }
    return val << 24;
}
