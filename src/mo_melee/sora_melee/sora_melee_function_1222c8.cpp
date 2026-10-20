#include <types.h>
#pragma force_active on

struct ftSlotManager {
    u32 pad[0x460 / 4];
    void* slots[1];
};

extern "C" void* fn_27_1222C8(ftSlotManager* self, u32 index) {
    return self->slots[index];
}
