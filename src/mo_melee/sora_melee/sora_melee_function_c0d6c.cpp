#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_C1054(char*);

void fn_27_C0D6C(char* self, u32 arg1, u32 arg2, const u32* flags) {
    if ((((flags[3]) >> 3) & 1) == 0) {
        fn_27_C1054(self + 0xb8);
        *reinterpret_cast<u32*>(self + 0x13c) = 0x32;
    }
}
}
