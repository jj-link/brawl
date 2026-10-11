#include <so/kinetic/so_kinetic_energy.h>
#include <so/work/so_general_work_simple.h>
#include <mo_fighter/ft_lucas/ft_lucas_speed_pair.h>

class LucasSpeedEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser* accesser);
    virtual LucasSpeedPair getSpeed();
};

extern "C" const float lbl_114_rodata_8;

extern "C" void fn_114_CCCC(void* object, soKineticEnergy* energy) {
    LucasSpeedPair speed = reinterpret_cast<LucasSpeedEnergyView*>(energy)->getSpeed();
    fn_114_C4D4(object, &speed, lbl_114_rodata_8);
}

extern "C" u32 fn_114_CD24(soGeneralWorkSimple* work) {
    return work->soGeneralWorkSimple::getFlagWorkSize();
}
