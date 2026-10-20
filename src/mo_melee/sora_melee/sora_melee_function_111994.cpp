#include <ft/ft_owner.h>
#pragma force_active on

void ftOwner::setHitPointMax(float f) {
    *(float*)((char*)m_data + 8) = f;
}
