#include <types.h>
#pragma force_active on

struct FlagHolder {
    u8 pad0[8];
    u32 flags;
};

extern "C" void fn_27_19E44C(FlagHolder* self) {
    self->flags |= 0x400000;
}
