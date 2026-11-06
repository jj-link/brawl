#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
extern "C" void fn_123_F2B4(void*, soModuleAccesser*);
extern "C" void fn_123_F664(void*, soModuleAccesser*);
extern "C" void fn_123_F7D0(void*, soModuleAccesser*);

extern "C" void fn_123_F0B0(void* self, soModuleAccesser* accesser) {
    if (accesser->getStatusModule().getPrevStatusKind(0) != 0x120) {
        soWorkManageModule& work = accesser->getWorkManageModule();
        int value = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5dc8, 0);
        work.setInt(value, 0x20000003);
    }
    if (accesser->getStatusModule().getPrevStatusKind(0) != 0x124 &&
        accesser->getStatusModule().getPrevStatusKind(0) != 0x120) {
        accesser->getWorkManageModule().onFlag(0x22000012);
    } else {
        fn_123_F2B4(self, accesser);
        fn_123_F664(self, accesser);
        fn_123_F7D0(self, accesser);
    }
}