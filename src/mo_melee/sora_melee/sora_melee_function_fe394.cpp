#include <types.h>
#pragma force_active on

struct soraMeleeThing {
    s32 m_00;
    s32 m_04;
    s32 m_08;
};

extern "C" s32 fn_27_FE394(soraMeleeThing *obj) {
    return obj->m_08 >> 30;
}
