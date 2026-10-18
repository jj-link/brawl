#include <types.h>
#pragma force_active on

class soStopModuleImpl {
public:
    bool isSpecialStop();
private:
    u8 m_pad[0x1c];
    struct {
        u8 : 5;
        u8 m_special : 1;
        u8 : 2;
    } m_flags;
};

bool soStopModuleImpl::isSpecialStop()
{
    return m_flags.m_special;
}
