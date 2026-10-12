#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" void fn_99_10D7C(void*, soModuleAccesser* accesser) {
    float duration = soValueAccesser::getConstantInt(accesser, 0x5dc1, 0);
    float speed = soValueAccesser::getConstantFloat(accesser, 0xfa0, 0);
    speed /= duration;
    accesser->getWorkManageModule().setFloat(speed, 0x21000000);
}
