#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct PikachuMediatorEnergy;
namespace {
// The dispatcher's special update argument is passed by value in r4.
struct PikachuSpecialEnergyUpdateArgument {
    bool state;
    PikachuSpecialEnergyUpdateArgument() : state(false) {}
};
struct PikachuSpecialEnergyState {
    char base[8];
    Vec2f speed;
    char parameters[0x18];
    Vec2f previousSpeed;
};
}
extern "C" {
float fn_98_E878(float, float, float);
Vec2f* fn_98_C46C(Vec2f*, const Vec2f&);
}

#pragma always_inline on
extern "C" void fn_98_E704(PikachuMediatorEnergy* energy,
                            PikachuSpecialEnergyUpdateArgument,
                            soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    Vec2f stick;
    stick.m_x = accesser->getControllerModule().getStickX();
    stick.m_y = accesser->getControllerModule().getStickY();
    float range;
    float threshold = soValueAccesser::getConstantFloat(accesser, 0xc2d, 0);
    range = soValueAccesser::getConstantFloat(accesser, 0xc36, 0);
    stick.m_x = fn_98_E878(stick.m_x, threshold, range);
    stick.m_y = fn_98_E878(stick.m_y, threshold, range);
    Vec2f scale;
    scale.m_x = soValueAccesser::getConstantFloat(accesser, 0xfcb, 0);
    scale.m_y = soValueAccesser::getConstantFloat(accesser, 0xfcc, 0);
    Vec2f speed;
    speed.m_x = scale.m_x * stick.m_x;
    speed.m_y = scale.m_y * stick.m_y;
    float multiplier = work.getFloat(0x21000004);
    speed.m_x *= multiplier;
    speed.m_y *= multiplier;
    PikachuSpecialEnergyState* state = reinterpret_cast<PikachuSpecialEnergyState*>(energy);
    fn_98_C46C(&state->speed, speed);
    fn_98_C46C(&state->previousSpeed, speed);
}
