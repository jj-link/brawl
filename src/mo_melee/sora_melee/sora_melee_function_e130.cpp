#include <types.h>
#pragma force_active on

class soModelModuleImpl {
public:
    bool isRefFB();
private:
    u8 m_pad[0xc5];
    struct {
        u8 m_a : 2;
        u8 m_flag : 1;
        u8 m_b : 5;
    } m_bits;
};

bool soModelModuleImpl::isRefFB()
{
    return m_bits.m_flag;
}
