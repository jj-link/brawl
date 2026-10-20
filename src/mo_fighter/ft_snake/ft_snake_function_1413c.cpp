#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_122_data_D744[], lbl_122_data_81AC[];
extern const float lbl_122_rodata_38;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_122_1413C(void*, soModuleAccesser* accesser) {
    bool flag = false;
    if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
        if (accesser->getKineticModule().getEnergy(1)->getSpeed().m_y <= lbl_122_rodata_38)
            flag = true;
    }
    if (flag) {
        void* p = __dynamic_cast(accesser->getKineticModule().getEnergy(1), 0,
                                 lbl_122_data_D744, lbl_122_data_81AC, 1);
        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(p) + 0xC) =
            lbl_122_rodata_38;
    }
}
