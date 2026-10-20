#include <types.h>
#pragma force_active on

extern "C" {
struct fn_27_FE674_obj {
    u32 _0;
    u32 _4;
    s32 _8;
};

s32 fn_27_FE674(const fn_27_FE674_obj* p) {
    return p->_8 >> 28;
}
}
