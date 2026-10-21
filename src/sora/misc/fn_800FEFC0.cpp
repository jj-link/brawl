#include <types.h>
#pragma force_active on

extern "C" {

struct Table {
    u8 pad[0x10];
    void (*fn)(void*, f32, f32, f32);
};

extern const Table lbl_804091B8;

struct Self {
    u8 pad[0x110];
    s32 state;
    u8 pad1[4];
    f32 x;
    f32 y;
    f32 z;
};

void fn_800FEFC0(Self* self, f32 a, f32 b, f32 c) {
    self->x = a;
    self->y = b;
    self->z = c;
    self->state = 2;

    if (lbl_804091B8.fn)
        lbl_804091B8.fn(self, a, b, c);
}

}
