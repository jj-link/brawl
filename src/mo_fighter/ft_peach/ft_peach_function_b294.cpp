#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_B3D0(void* array, s32 index);
void* fn_103_B3B8(void* array, s32 index);
int fn_27_8D3E4(void* p);

void fn_103_B294(void* self) {
    u8* p = static_cast<u8*>(self);
    for (s32 i = 0; i < 1; i++) {
        void* r = fn_103_B3D0(p + 0xDD10, i);
        if (fn_27_8D3E4(static_cast<u8*>(r) + 0x88) == 0) {
            return;
        }
    }
    for (s32 j = 0; j < 1; j++) {
        void* r = fn_103_B3B8(p + 0xC, j);
        if (fn_27_8D3E4(static_cast<u8*>(r) + 0x88) == 0) {
            return;
        }
    }
}
}
