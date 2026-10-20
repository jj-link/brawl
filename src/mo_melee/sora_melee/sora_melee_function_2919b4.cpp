#include <types.h>
#pragma force_active on

struct Foo {
    s32 a;
    s32 b;
    s32 c;
};

extern "C" s32 fn_27_2919B4(Foo* self) {
    return (self->c >> 19) & 1;
}
