#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_104_1E4D0(void*, soModuleAccesser* accesser) {
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(0xe));
    int* params = *reinterpret_cast<int**>(reinterpret_cast<char*>(data) + 0x80);
    accesser->getWorkManageModule().setInt(params[1], 0x20000004);
}
