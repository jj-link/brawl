#include <types.h>
#pragma force_active on

extern "C" void fn_41_2A4C0(void* entry, s32 id);

struct LoopData {
    u8 pad[0x1C];
    void* entries; // 0x1C: base of 8-byte entry array
    s32* ids;      // 0x20: array of ids/values
    s32 count;     // 0x24: number of entries
};

extern "C" void fn_41_28E00(LoopData* self) {
    for (s32 i = 0; i < self->count; i++) {
        fn_41_2A4C0((u8*)self->entries + i * 8, self->ids[i]);
    }
}
