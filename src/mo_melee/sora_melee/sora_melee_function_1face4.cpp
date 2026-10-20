#include <types.h>
#pragma force_active on

struct AiInput {
    char pad0[0x3C];
    u16 flags;
};

extern "C" void fn_27_1FAD54(AiInput* self);

extern "C" void fn_27_1FACE4(AiInput* self, u32 flag) {
    if (flag == 1) {
        if ((self->flags & 0x8000) == 0) {
            fn_27_1FAD54(self);
        }
    }
    if (flag) {
        self->flags |= 0x8000;
    } else {
        self->flags &= 0x7FFF;
    }
}
