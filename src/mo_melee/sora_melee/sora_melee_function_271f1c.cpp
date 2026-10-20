#include <types.h>
#pragma force_active on

extern "C" void fn_27_272258(void* a, void* b, u32 c);

extern "C" void fn_27_271F1C(u8* self, void* a, s32 n, u32 c) {
    if (n == 0) {
        fn_27_272258(self + 4, a, c);
    }
    if (n == 1) {
        fn_27_272258(self + 0x20, a, c);
    }
}
