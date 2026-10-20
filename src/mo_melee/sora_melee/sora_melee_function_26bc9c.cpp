#include <types.h>
#pragma force_active on

class grGimmick {
public:
    u8 pad[0xd4];
    u32 *m_root;
    s32 m_count;
    void setCalcuCallbackRoot(u32 v);
};

void grGimmick::setCalcuCallbackRoot(u32 v) {
    if (m_count <= 0) return;
    m_root[0] = 0;
    m_root[1] = v;
}
