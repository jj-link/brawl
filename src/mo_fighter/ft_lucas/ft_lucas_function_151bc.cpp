#include <types.h>
#pragma force_active on

extern "C" void fn_114_8AE8(void* self, int value);
extern "C" char lbl_114_data_9148[];

struct LucasState {
    void* vtable;
    u8 flag;
    u8 enabled : 1;
    u8 reserved : 7;
    u8 state;
};

extern "C" LucasState* fn_114_151BC(LucasState* self, int value) {
    fn_114_8AE8(self, value);
    self->enabled = !value;
    self->state = 0;
    self->vtable = lbl_114_data_9148;
    return self;
}
