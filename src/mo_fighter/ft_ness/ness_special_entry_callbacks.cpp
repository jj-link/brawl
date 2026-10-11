#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>

extern "C" unsigned char lbl_101_data_8AC0[];

extern "C" void* fn_101_117A8(void* object) {
    *static_cast<void**>(object) = lbl_101_data_8AC0;
    return object;
}

extern "C" void fn_101_117B8(void*, soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    g_ftCommonDataAccesser.getData(static_cast<ftKind>(10));
    work.setInt(1, 0x20000003);
}
