#include <types.h>
#pragma force_active on

struct Obj {
    s32 _0;
    s32 _4;
    s32 _8;
};

extern "C" s32 fn_27_1A204C(const Obj* obj) {
    return obj->_8 >> 27;
}
