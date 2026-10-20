#include <types.h>
#pragma force_active on

struct Fn27Inner {
    char pad[0x10];
    u32 value;
};

struct Fn27Outer {
    char pad[0x10];
    Fn27Inner* inner;
};

extern "C" {
bool fn_27_234D88(Fn27Outer* self, u32* out) {
    Fn27Inner* p = self->inner;
    if (p != nullptr) {
        *out = p->value;
        return true;
    }
    return false;
}
}
