#include <types.h>
#pragma force_active on

struct FlagHolder {
    u8 pad[8];
    u32 flags;
};

extern "C" void fn_27_19BA00(FlagHolder* self) {
    self->flags |= 0x00080000;
}
