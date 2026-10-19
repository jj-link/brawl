#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void fn_96_15E44(void*, soModuleAccesser*);
}

extern "C" void fn_96_15D6C(void* process, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000012)) {
        fn_96_15E44(process, accesser);
    }
}
