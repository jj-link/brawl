#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/posture/so_posture_module_simple.h>
#include <types.h>
#pragma force_active on
struct SpeedBits { u32 x; u32 y; };
struct LocalNormalEnergyView { virtual void a(); virtual void b(); virtual SpeedBits getSpeedBits(); };
struct EnergyFields { char pad[8]; Vec2f speed; };
extern "C" {
extern const char lbl_27_data_13690[], lbl_27_data_CDF8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
extern "C" void fn_27_17A374(void*, soModuleAccesser* accesser) {
    int flag = accesser->getSituationModule().getKind() == 0;
    LocalNormalEnergyView* energy = (LocalNormalEnergyView*)__dynamic_cast(accesser->getKineticModule().getEnergy(flag + 2), 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
    SpeedBits first;
    SpeedBits speed;
    speed = energy->getSpeedBits();
    first = speed;
    float* values = (float*)&first;
    float lr = -accesser->getPostureModule().getLr();
    float c = soValueAccesser::getConstantFloat(accesser, 0xcc5, 0);
    values[0] += c * lr;
    EnergyFields* fields = (EnergyFields*)energy;
    fields->speed.m_x = values[0];
    fields->speed.m_y = values[1];
    ((unsigned char*)energy)[5] |= 0x80;
}