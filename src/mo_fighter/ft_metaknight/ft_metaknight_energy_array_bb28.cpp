#include <so/kinetic/so_kinetic_energy.h>

extern "C" void fn_111_B93C(soKineticEnergy* energy, void* context);
extern "C" void fn_111_C3AC(s16* destination, const s16* source);
#pragma dont_inline on
extern "C" int fn_111_BBD0(void* object, const s16* event, void* context);
#pragma dont_inline reset

extern "C" soKineticEnergy* fn_111_BB28(void* array, int index) {
    if (index == 0) {
        return reinterpret_cast<soKineticEnergy*>(static_cast<u8*>(array) + 0xC);
    }
    return 0;
}

extern "C" void fn_111_BB40(void* array, const s16* event, void* context) {
    u8* object = static_cast<u8*>(array);
    soKineticEnergy* energy = reinterpret_cast<soKineticEnergy*>(object + 0xC);
    if ((*event & 2) != 0 && energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
        fn_111_B93C(energy, context);
    }
    s16 copy;
    fn_111_C3AC(&copy, event);
    fn_111_BBD0(object + 4, &copy, context);
}

#pragma dont_inline on
extern "C" int fn_111_BBD0(void*, const s16*, void*) {
    return 0;
}
#pragma dont_inline reset
