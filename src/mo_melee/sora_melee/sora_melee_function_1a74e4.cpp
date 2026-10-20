#include <types.h>
#pragma force_active on

struct SomeClass {
    u32 field0;
    u32 field4;
    s32 field8;
};

extern "C" s32 fn_27_1A74E4(SomeClass *self) {
    return self->field8 >> 29;
}
