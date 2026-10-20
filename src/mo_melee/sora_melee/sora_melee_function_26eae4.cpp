#include <types.h>
#pragma force_active on

class grGimmickMotionPath {
public:
    u8 pad0[0x158];
    f32 m_158;
    u8 pad1[0x174 - 0x15C];
    f32 m_174;

    bool isMoveEnd();
};

bool grGimmickMotionPath::isMoveEnd() {
    return __fabsf(m_158) < m_174;
}
