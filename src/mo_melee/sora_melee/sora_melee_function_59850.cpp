#include <so/controller/so_controller_module_impl.h>
#include <types.h>
#include <math.h>
#pragma force_active on

float soControllerModuleImpl::getStickAngle() {
    float x = getStickX();
    float y = getStickY();
    return (float)atan2(y, x);
}
