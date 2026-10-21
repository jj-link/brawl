#include <so/so_module_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>
#pragma force_active on

extern "C" const float lbl_110_rodata_174;

extern "C" void fn_110_19094(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    DededeGroundSpeedView* ground =
        reinterpret_cast<DededeGroundSpeedView*>(
            accesser->m_enumerationStart->m_groundModule);

    if (ground->isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
        float lr = accesser->m_enumerationStart->m_postureModule->getLr();
        Vec2f normal;
        const DededeSpeed& value =
            ground->getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0);
        Vec2f::copy(normal, *reinterpret_cast<const Vec2f*>(&value));
        float angle = lbl_110_rodata_174 *
                      atan2f(-(normal.m_x * lr), normal.m_y);
        work->setFloat(angle, 0x21000000);
    }
}
