#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

class soCollisionHitGroup {
public:
    s32 m_00;
    u16 m_04;
    u16 m_06;
    char m_08[0x2c - 0x08];
    u32 m_2c;
    char m_30[0x34 - 0x30];
    u8 m_34;
    soCollisionHitGroup();
};

soCollisionHitGroup::soCollisionHitGroup() {
    m_00 = -1;
    m_04 = 0;
    m_06 = 0;
    m_2c = 0;
    m_34 = 0;
}
