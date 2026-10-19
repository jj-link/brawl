#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_1F1C1C(void* p, s32 id) {
    u8* self = (u8*)p;
    if (id >= 0 && id < 7) {
        if (self + 0x4c) {
            void* sub = *(void**)(self + 0x4c + id * 4);
            if (sub) {
                return *(s8*)((u8*)sub + 0x98);
            }
        }
    }
    return 0;
}
}
