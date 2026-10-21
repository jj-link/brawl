#include <types.h>
#pragma force_active on

struct Foo {
    u32 pad[0xF0 / 4];
    u32 values[1];
};

extern "C" u32 fn_80112DAC(Foo* self, u32 index) {
    return self->values[index];
}
