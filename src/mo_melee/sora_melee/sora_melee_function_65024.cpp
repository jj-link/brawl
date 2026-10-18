#include <types.h>
#pragma force_active on

extern "C" {
struct SomeStruct {
    u8 pad[0x61];
    u8 field;
};

void fn_27_65024(SomeStruct* self) {
    self->field = 0;
}
}
