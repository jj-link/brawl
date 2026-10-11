#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct PikachuVortexParameterEvent { int kind; };
extern "C" void fn_27_1DB0F0(void*, const PikachuVortexParameterEvent*, soModuleAccesser*);

extern "C" void fn_98_1B76C(void* owner, const PikachuVortexParameterEvent* event, soModuleAccesser* accesser) {
    fn_27_1DB0F0(owner, event, accesser);
    if (event->kind == 0x455) {
        soWorkManageModule& work = accesser->getWorkManageModule();
        float acceleration;
        const float speedLimit = soValueAccesser::getConstantFloat(accesser, 0xfa6, 0);
        acceleration = soValueAccesser::getConstantFloat(accesser, 0xfa4, 0);
        work.setFloat(speedLimit, 0x11000003);
        work.setFloat(acceleration, 0x11000005);
    }
}
