#include <types.h>
#pragma force_active on

struct Inner {
    char pad[0xB0];
    float unkB0;
};

struct Self {
    char pad[0xE4];
    float unkE4;
};

struct Handle {
    Inner* ptr;
};

extern "C" void fn_800194AC(Self*, Handle);

extern "C" void fn_80019718(Self* self, const Handle& arg) {
    fn_800194AC(self, arg);
    self->unkE4 = arg.ptr->unkB0;
}
