#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>

extern "C" const float lbl_101_rodata_28;

extern "C" void fn_101_116AC(void*, soModuleAccesser* accesser, int eventKind) {
    if (eventKind == 25) {
        ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(10));
        // The existing ftData declaration does not yet describe this parameter block.
        unsigned char* parameters = *reinterpret_cast<unsigned char**>(
            reinterpret_cast<unsigned char*>(data) + 0x80);
        float value = *reinterpret_cast<float*>(parameters + 0x18);
        if (value > lbl_101_rodata_28) {
            accesser->getWorkManageModule().setFloat(value, 0x11000000);
        }
    }
}
