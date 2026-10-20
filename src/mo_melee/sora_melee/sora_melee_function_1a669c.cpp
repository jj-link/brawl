#include <types.h>
#pragma force_active on

struct FlagHolder {
    u32 m0;
    u32 m4;
    u32 m8;
};

extern "C" u32 fn_27_1A669C(FlagHolder* self) {
    return (self->m8 >> 1) & 1;
}
