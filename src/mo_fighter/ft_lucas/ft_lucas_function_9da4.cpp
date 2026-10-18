#include <types.h>
#pragma force_active on

extern "C" void fn_114_8AE8(void* self, u8 value);
extern "C" char lbl_114_data_3218[];

struct LucasObjectWords {
    u32 w[9];
};

extern "C" LucasObjectWords* fn_114_9DA4(LucasObjectWords* self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    fn_114_8AE8(self, 0);
    self->w[2] = (u32)lbl_114_data_3218;
    self->w[0] = (u32)(lbl_114_data_3218 + 8);
    self->w[3] = a;
    self->w[4] = b;
    self->w[5] = c;
    self->w[6] = d;
    self->w[7] = e;
    self->w[8] = f;
    return self;
}
