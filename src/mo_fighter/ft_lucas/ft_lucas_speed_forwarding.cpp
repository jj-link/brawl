#include <so/kinetic/so_kinetic_energy.h>
#include <so/work/so_general_work_simple.h>
#include <types.h>

// Keep the register-returned vector as a POD, as in the neighboring fighter
// kinetic views, so forwarding its address does not introduce a Vec2f copy.
struct LucasSpeedPair {
    float x;
    float y;
};
static_assert(sizeof(LucasSpeedPair) == 8, "Speed return ABI mismatch");

class LucasSpeedEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser* accesser);
    virtual LucasSpeedPair getSpeed();
};

extern "C" const float lbl_114_rodata_8;
extern "C" void fn_114_C4D4(void* object, const LucasSpeedPair* speed, float scale);

extern "C" void fn_114_CCCC(void* object, soKineticEnergy* energy) {
    LucasSpeedPair speed = reinterpret_cast<LucasSpeedEnergyView*>(energy)->getSpeed();
    fn_114_C4D4(object, &speed, lbl_114_rodata_8);
}

extern "C" u32 fn_114_CD24(soGeneralWorkSimple* work) {
    return work->soGeneralWorkSimple::getFlagWorkSize();
}
