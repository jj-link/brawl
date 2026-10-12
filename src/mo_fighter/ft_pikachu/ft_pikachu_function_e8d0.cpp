#include <so/so_module_accesser.h>

struct PikachuEnergyParameters {
    int duration;
    float value04;
    float value08;
};
struct PikachuEnergyParameterView {
    char prefix[8];
    const PikachuEnergyParameters* parameters;
};
// The concrete energy's parameter at 0x10 is not exposed by the module headers.
struct PikachuEnergyView {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char suspended;
    unsigned char padding;
    float value08, value0c, value10;
    inline void disable() { enabled = 0; }
};
extern "C" {
extern const char lbl_98_data_600[], lbl_98_data_2F88[];
extern const char lbl_98_data_769C[], lbl_98_data_24B0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
PikachuEnergyParameterView* fn_98_9530(void*);
}

extern "C" void fn_98_E8D0(void*, soModuleAccesser* accesser) {
    const PikachuEnergyParameters* parameters = fn_98_9530(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_600, lbl_98_data_2F88, 1))->parameters;
    soKineticModule& kinetic = accesser->getKineticModule();
    soWorkManageModule& work = accesser->getWorkManageModule();
    reinterpret_cast<PikachuEnergyView*>(kinetic.getEnergy(0))->disable();
    reinterpret_cast<PikachuEnergyView*>(kinetic.getEnergy(1))->disable();
    reinterpret_cast<PikachuEnergyView*>(kinetic.getEnergy(2))->disable();
    reinterpret_cast<PikachuEnergyView*>(kinetic.getEnergy(3))->disable();
    PikachuEnergyView* energy = static_cast<PikachuEnergyView*>(__dynamic_cast(
        kinetic.getEnergy(1), 0, lbl_98_data_769C, lbl_98_data_24B0, 1));
    energy->value10 = parameters->value08;
    work.setInt(parameters->duration, 0x20000002);
}
