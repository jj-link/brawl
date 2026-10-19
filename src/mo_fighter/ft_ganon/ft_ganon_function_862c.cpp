#include <ft/ft_common_data_accesser.h>
#pragma force_active on

extern "C" void* fn_109_862C() {
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(20));
    return *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(data) + 0x88);
}
