#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <ft/ft_common_data_accesser.h>
#pragma force_active on

struct KirbyFighterBase {
    char pad[0x3c];
};

#define KIRBY_VF(n) virtual void vf##n();
#define KIRBY_VF10(t) \
    KIRBY_VF(t##0) KIRBY_VF(t##1) KIRBY_VF(t##2) KIRBY_VF(t##3) KIRBY_VF(t##4) \
    KIRBY_VF(t##5) KIRBY_VF(t##6) KIRBY_VF(t##7) KIRBY_VF(t##8) KIRBY_VF(t##9)

class KirbyFighter : public KirbyFighterBase {
public:
    KIRBY_VF10(0) KIRBY_VF10(1) KIRBY_VF10(2) KIRBY_VF10(3) KIRBY_VF10(4)
    KIRBY_VF10(5) KIRBY_VF10(6) KIRBY_VF10(7) KIRBY_VF10(8) KIRBY_VF10(9)
    KIRBY_VF10(10) KIRBY_VF10(11) KIRBY_VF10(12) KIRBY_VF10(13) KIRBY_VF10(14)
    KIRBY_VF10(15) KIRBY_VF10(16) KIRBY_VF10(17)
    KIRBY_VF(180) KIRBY_VF(181) KIRBY_VF(182) KIRBY_VF(183)
    KIRBY_VF(184) KIRBY_VF(185)
    virtual int kind();
};

struct KirbyParams {
    char pad[0x74];
    float value;
    float pad2;
    float value2;
};

struct KirbyInfo {
    char pad[8];
    float* values;
};

// Byte 5 of soKineticEnergy holds the enable bit (soEnable::m_isEnable, high bit).
struct KirbyEnergyFlags {
    char pad[5];
    unsigned char enable : 1;
};

extern "C" {
extern const char lbl_96_data_608[];
extern const char lbl_96_data_68D8[];
extern const char lbl_96_data_B050[];
extern const char lbl_96_data_5E00[];
extern const float lbl_96_rodata_28;
extern const float lbl_96_rodata_2C;

void* __dynamic_cast(void*, long, const void*, const void*, short);
KirbyInfo* fn_96_AF98(void*);
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
void fn_27_15CF5C(soKineticEnergy*, float);
void fn_96_138F8(soKineticEnergy*, Vec2f*);
}

extern "C" void fn_96_136CC(void*, soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    soKineticModule& kinetic = accesser->getKineticModule();
    work.setInt(accesser->getSituationModule().getKind(), 0x20000002);
    kinetic.clearSpeedAll();
    soKineticEnergy* e0 = kinetic.getEnergy(0);
    reinterpret_cast<KirbyEnergyFlags*>(e0)->enable = 0;
    soKineticEnergy* e1 = kinetic.getEnergy(1);
    reinterpret_cast<KirbyEnergyFlags*>(e1)->enable = 0;
    soKineticEnergy* e2 = kinetic.getEnergy(2);
    reinterpret_cast<KirbyEnergyFlags*>(e2)->enable = 0;
    soKineticEnergy* e3 = kinetic.getEnergy(3);
    reinterpret_cast<KirbyEnergyFlags*>(e3)->enable = 0;
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
        kinetic.getEnergy(2), 0, lbl_96_data_B050, lbl_96_data_5E00, 1));
    KirbyFighter* fighter = static_cast<KirbyFighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_96_data_608, lbl_96_data_68D8, 1));
    KirbyParams* params = reinterpret_cast<KirbyParams*>(
        g_ftCommonDataAccesser.getParam((ftKind)fighter->kind()));
    KirbyInfo* info = fn_96_AF98(fighter);
    reinterpret_cast<KirbyEnergyFlags*>(energy)->enable = 1;
    Vec2f speed(lbl_96_rodata_28, lbl_96_rodata_28);
    Vec3f rot;
    energy->resetEnergy(4, &speed,
        fn_96_BC54(&rot, lbl_96_rodata_28, lbl_96_rodata_28, lbl_96_rodata_28),
        accesser);
    fn_27_15CF5C(energy, params->value * info->values[1]);
    Vec2f v(params->value2, lbl_96_rodata_2C);
    fn_96_138F8(energy, &v);
}
