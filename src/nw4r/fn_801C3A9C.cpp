#include <types.h>
#pragma force_active on

struct UnknownStruct {
    u32 pad[0xB8 / 4];
    void* entries[16];
};

extern "C" void* fn_801C3A9C(UnknownStruct* self, s32 index) {
    if (index > 0xF) {
        return 0;
    }
    return self->entries[index];
}
