#include <types.h>
#pragma force_active on

struct UnkStruct {
    char pad0[0x1C];
    u8* base;      // 0x1C
    char pad1[4];  // 0x20
    int count;     // 0x24
};

extern "C" unsigned fn_41_28DC8(UnkStruct* self, int value);
extern "C" void fn_41_2A4F0(void* self, u32 value);

extern "C" {
void fn_41_28F74(UnkStruct* self, u32 p2, int index) {
    if (fn_41_28DC8(self, index) == 1) {
        return;
    }
    if (index == -1) {
        for (int i = 0; i < self->count; i++) {
            fn_41_2A4F0(self->base + (i << 3), p2);
        }
    } else {
        fn_41_2A4F0(self->base + (index << 3), p2);
    }
}
}
