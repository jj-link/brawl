#include <ft/ft_owner.h>
#pragma force_active on

void ftOwner::setSlipMul(float mul) {
    *(float*)((char*)m_data + 0x4c0) = mul;
}
