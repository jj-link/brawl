#include <types.h>
#pragma force_active on

class soCollisionAttackAbsolute {
public:
    soCollisionAttackAbsolute();
    u8 pad[0x24];
    float m_24;
    float m_28;
    float m_2c;
    u8 pad2[0x38 - 0x30];
    u32 m_38;
};

extern "C" extern const float lbl_27_rodata_F00;

soCollisionAttackAbsolute::soCollisionAttackAbsolute() {
    float zero = lbl_27_rodata_F00;
    m_24 = zero;
    m_28 = zero;
    m_2c = zero;
    m_38 = m_38 & ~0x1f;
}
