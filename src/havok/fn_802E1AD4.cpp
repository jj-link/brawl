#include <types.h>
#pragma force_active on

extern "C" void fn_802FABFC(void*, void*);

struct Object {
    u8 pad[0x58];
    u8* ptr;

    s32 state() const {
        if (ptr == 0)
            return 0;
        return (ptr[0x27] >> 6) & 3;
    }
};

extern "C" void fn_802E1AD4(Object* self) {
    if ((s8)(u8)self->state() == 0)
        return;

    fn_802FABFC(*(void**)((u8*)self + 8), self->ptr);
}
