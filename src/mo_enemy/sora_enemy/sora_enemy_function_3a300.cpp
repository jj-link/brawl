#include <em/em_external_value_accesser.h>
#pragma force_active on

extern "C" void fn_41_A87C(void*);

extern "C" void fn_41_3A300(Enemy* self) {
    fn_41_A87C(self);

    reinterpret_cast<soModuleAccesser**>(
        reinterpret_cast<unsigned char*>(self) + 0x60)[0]
        ->getWorkManageModule().onFlag(0x12000006);
}
