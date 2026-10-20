#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_92_data_639C[], lbl_92_data_1874[], lbl_92_data_62B8[];
extern const float lbl_92_rodata_10;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_92_BA0C(Vec2f*, const Vec2f*);
}

struct EnergyFlag {
    unsigned char enabled : 1;
};

extern "C" void fn_92_CD70(void*, soModuleAccesser* accesser)
{
    soWorkManageModule& work = accesser->getWorkManageModule();
    soSituationModule& situation = accesser->getSituationModule();
    soKineticModule& kinetic = accesser->getKineticModule();
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(1));
    const unsigned char* parameters =
        *reinterpret_cast<const unsigned char**>(
            reinterpret_cast<unsigned char*>(data) + 0x80);

    unsigned char* gravity = static_cast<unsigned char*>(__dynamic_cast(
        kinetic.getEnergy(1), 0, lbl_92_data_639C, lbl_92_data_1874, 1));
    unsigned char* stop = static_cast<unsigned char*>(__dynamic_cast(
        kinetic.getEnergy(3), 0, lbl_92_data_62B8, lbl_92_data_1874, 1));

    if (situation.getKind() == 0) {
        kinetic.changeKinetic(6, accesser);
    } else {
        kinetic.changeKinetic(10, accesser);

        Vec2f speed;
        speed.m_x = *reinterpret_cast<const float*>(parameters + 4);
        speed.m_y = lbl_92_rodata_10;
        fn_92_BA0C(reinterpret_cast<Vec2f*>(stop + 0x20), &speed);

        *reinterpret_cast<float*>(gravity + 0x10) =
            -*reinterpret_cast<const float*>(parameters + 8);

        if (!work.isFlag(0x22000011)) {
            reinterpret_cast<EnergyFlag*>(gravity + 5)->enabled = 0;
        }
    }
}
