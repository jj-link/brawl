#include <so/controller/so_controller_module_impl.h>
#include <math.h>
#pragma force_active on

float soControllerModuleImpl::getSubStickDir() {
    return atan2(getSubStickY(), (float)fabs(getSubStickX()));
}
