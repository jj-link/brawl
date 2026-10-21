#include <so/so_module_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>
#pragma force_active on

extern "C" {
extern const float lbl_110_rodata_150;
}

#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_110_184E8(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    DededeGroundSpeedView* ground =
        reinterpret_cast<DededeGroundSpeedView*>(
            accesser->m_enumerationStart->m_groundModule);

    if (ground->isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
        float lr = accesser->m_enumerationStart->m_postureModule->getLr();
        Vec2f normal;
        DededeSpeed result =
            ground->getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0);
        Vec2f::copy(normal, *reinterpret_cast<const Vec2f*>(&result));

        float y = normal.m_y;
        float x = -(normal.m_x * lr);
        work->setFloat(
            lbl_110_rodata_150 * static_cast<float>(atan2(x, y)),
            0x21000000);
    }
}
