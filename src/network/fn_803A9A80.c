#include <types.h>
#pragma force_active on

struct Fn803A9A80Obj {
    u32 m_00;
    u32 m_04;
    s32 m_08;
    u32 m_0c;
};

void fn_803A9A80(struct Fn803A9A80Obj* obj, s32 arg1) {
    if (obj->m_0c == 1 || arg1 == 0) {
        obj->m_08 = obj->m_00;
        return;
    }
    obj->m_08 = arg1;
}
