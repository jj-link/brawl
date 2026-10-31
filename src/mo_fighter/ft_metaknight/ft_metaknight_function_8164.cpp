#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_111_8164(void* object, int motion, int previous,
                            void* argument, soModuleAccesser* accesser) {
    if (motion >= 0x1BE) return;
    if (motion < 0x1BC) return;
    accesser->getGroundModule().setShapeFlag(static_cast<soGroundShapeImpl::ShapeFlagId>(3), true, 0);
}
