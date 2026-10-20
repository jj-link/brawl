#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

class soCollisionHitGroup {
public:
    void setInvincibleGlobal();

    u8 m_00[0x20];
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u8 m_2c[5];
    u8 m_31;
    u8 m_32;
};

void soCollisionHitGroup::setInvincibleGlobal() {
    u8 a = m_31;
    m_32 = 1;
    if (a == 1 || m_24 != 0) {
        m_20 = 2;
        return;
    }
    if (m_32 == 1 || m_28 != 0) {
        m_20 = 1;
        return;
    }
    m_20 = 0;
}
