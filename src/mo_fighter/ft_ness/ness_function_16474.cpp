#include <so/so_module_accesser.h>
#include <so/collision/so_collision_hit_module_impl.h>
#pragma force_active on

extern "C" void fn_101_16474(void*, soModuleAccesser* accesser) {
    accesser->getCollisionHitModule().setStatus(0, 0, 0);
    accesser->getCollisionHitModule().setStatus(1, 3, 0);
}
