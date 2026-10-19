#include <types.h>
#pragma force_active on

struct Owner {
    u8 pad[0x1bc];
    void* result;
};

extern "C" void fn_34_11A0(Owner* self);

extern "C" void* fn_34_1050(Owner* self) {
    fn_34_11A0(self);
    return self->result;
}
