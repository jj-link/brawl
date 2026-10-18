#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

class soStopModuleImpl {
public:
    u8 m_pad[0x1c];
    struct {
        u8 hi : 2;
        u8 damage : 1;
        u8 lo : 5;
    } m_bits;
    bool isDamage();
};

bool soStopModuleImpl::isDamage()
{
    return m_bits.damage;
}
