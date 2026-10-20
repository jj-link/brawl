#include <types.h>
#pragma force_active on

struct fn27_140404_Obj {
    u8 pad[0xc];
    s32 m_word0c;
    u8 pad2[4];
    s32 m_word14;
};

extern "C" {
s32 fn_27_140404(fn27_140404_Obj* obj) {
    s32 v = obj->m_word14;
    if (v != -1) {
        return v;
    }
    return obj->m_word0c;
}
}
