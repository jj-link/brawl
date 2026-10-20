#include <types.h>
#pragma force_active on

struct Obj {
    u32 _0;
    u32 _4;
    u32 _8;
};

extern "C" u32 fn_27_CBA6C(Obj* self) {
    return (self->_8 >> 19) & 1;
}
