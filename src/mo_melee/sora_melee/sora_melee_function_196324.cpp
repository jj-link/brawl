#include <StaticAssert.h>
#include <so/so_module_accesser.h>
#include <so/controller/so_controller_module_impl.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_26E8;

extern "C" void fn_27_196324(soModuleAccesser* accesser, float param) {
    s32 frames = (s32)(lbl_27_rodata_26E8 * param);
    if (frames >= 1) {
        accesser->m_enumerationStart->m_controllerModule->setRumble(6, frames, true, -1);
    }
}
