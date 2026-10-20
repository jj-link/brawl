#include <ft/ft_owner.h>
#pragma force_active on

int ftOwner::getStockCount() {
    return *(int*)((char*)m_data + 0x34);
}
