#include <types.h>
#pragma force_active on

class soStopModuleImpl {
public:
    bool isHit();
private:
    u8 m_pad[0x1c];
    struct {
        u8 m_a : 1;
        u8 m_hit : 1;
        u8 m_rest : 6;
    } m_flag;
};

bool soStopModuleImpl::isHit() {
    return m_flag.m_hit;
}
