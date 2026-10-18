#include <types.h>
#pragma force_active on

struct LucasInit {
    void* vtable;
    u32 pad[3];
    u32 a;
    u32 b;
    u32 c;
};

extern "C" {
extern u8 lbl_114_data_366C[];
}

extern "C" void fn_114_AB18(LucasInit* self, u32 a, u32 b, u32 c) {
    self->vtable = lbl_114_data_366C;
    self->a = a;
    self->b = b;
    self->c = c;
}
