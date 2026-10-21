#include <types.h>
#pragma force_active on

extern "C" void fn_802A1D88(s32);

extern "C" s32 fn_802FB2E8(void* self, void* unused, s32 ptr) {
    if (ptr != 0) {
        fn_802A1D88(ptr);
    }
    return ptr + 0x50;
}
