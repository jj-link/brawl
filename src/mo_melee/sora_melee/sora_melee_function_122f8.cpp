#include <types.h>
#pragma force_active on

extern "C" void fn_80095990(void* obj, u32* arg);

extern "C" void fn_27_122F8(u8* self, u32 arg) {
    u8* p = *(u8**)(self + 0x2c);
    if (p[8] == 0) {
        fn_80095990(*(void**)(p + 0x0), &arg);
    } else {
        fn_80095990(*(void**)(p + 0x4), &arg);
    }
}
