#include <types.h>
#pragma force_active on

struct grGimmickRot {
    u8 pad[0x14];
    float m_rotX;
    float m_rotY;
    float m_rotZ;
};

class grGimmick {
public:
    void setRot(float x, float y, float z);

private:
    u8 pad[0xd4];
    grGimmickRot* m_rot;
};

void grGimmick::setRot(float x, float y, float z) {
    grGimmickRot* rot = m_rot;
    if (rot == 0) {
        return;
    }
    rot->m_rotX = x;
    rot->m_rotY = y;
    rot->m_rotZ = z;
}
