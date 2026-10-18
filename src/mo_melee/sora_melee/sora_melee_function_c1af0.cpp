#include <types.h>
#pragma force_active on

struct FnSrc27C1AF0Obj {
    u8 pad[0x1c];
    s16 m_field;
};

extern "C" {
bool fn_27_C1AF0(FnSrc27C1AF0Obj* obj, s16 value) {
    if (obj->m_field == -1) {
        obj->m_field = value;
        return true;
    }
    return false;
}
}
