#include <gr/gr_gimmick.h>
#include <types.h>
#pragma force_active on

struct grGimmickScaleTarget {
    char _pad[0x20];
    float m_x;
    float m_y;
    float m_z;
};

void grGimmick::setScale(float x, float y, float z) {
    grGimmickScaleTarget* target = *(grGimmickScaleTarget**)((char*)this + 0xd4);
    if (target == nullptr) {
        return;
    }
    target->m_x = x;
    target->m_y = y;
    target->m_z = z;
}
