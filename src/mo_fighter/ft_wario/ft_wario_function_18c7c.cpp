#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

extern "C" const float lbl_110_rodata_16C;

#pragma always_inline on
#pragma inline_depth(8)

extern "C" void fn_110_18C7C(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration& modules = *accesser->m_enumerationStart;
    soWorkManageModule& work = *modules.m_workManageModule;
    soGroundModule& ground = *modules.m_groundModule;

    if (ground.isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
        float lr = accesser->m_enumerationStart->m_postureModule->getLr();
        Vec2f normal;
        Vec2f::copy(normal, ground.getTouchNormal(
            static_cast<grCollStatus::TouchMask>(8), 0));

        float y = normal.m_y;
        float x = -(normal.m_x * lr);
        work.setFloat(
            lbl_110_rodata_16C * static_cast<float>(atan2(x, y)),
            0x21000000);
    }
}
