#include <types.h>
#pragma force_active on

struct SceneCopyObj {
    u32 m_0;
    u32 m_4;
    u32 m_8;
    u32 m_c;
};

extern "C" {
void fn_1_1058C(SceneCopyObj* obj) {
    obj->m_c = obj->m_4;
}
}
