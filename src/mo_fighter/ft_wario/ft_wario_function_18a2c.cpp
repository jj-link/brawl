#include <so/so_module_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>
#pragma force_active on

extern "C" {
double atan2(double, double);
extern const float lbl_110_rodata_164;
}

extern "C" void fn_110_18A2C(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work =
        accesser->m_enumerationStart->m_workManageModule;
    DededeGroundSpeedView* ground =
        reinterpret_cast<DededeGroundSpeedView*>(
            accesser->m_enumerationStart->m_groundModule);

    if (ground->isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
        float lr = accesser->getPostureModule().getLr();
        Vec2f normal;
        DededeSpeed result =
            ground->getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0);
        Vec2f::copy(normal, *reinterpret_cast<const Vec2f*>(&result));

        float y = normal.m_y;
        float x = -(normal.m_x * lr);
        work->setFloat(
            lbl_110_rodata_164 * static_cast<float>(atan2(x, y)),
            0x21000000);
    }
}
