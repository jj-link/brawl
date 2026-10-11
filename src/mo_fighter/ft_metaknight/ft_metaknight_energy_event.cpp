#include <so/kinetic/so_kinetic_energy.h>

extern "C" void fn_111_C110(soKineticEnergy* energy, void* context);
extern "C" void fn_111_C3AC(s16* destination, const s16* source);
extern "C" int fn_111_C3A4(void* object, const s16* event, void* context);

extern "C" void fn_111_C314(void* array, const s16* event, void* context) {
    u8* object = static_cast<u8*>(array);
    soKineticEnergy* energy = reinterpret_cast<soKineticEnergy*>(object + 0xC);
    if ((*event & 4) != 0 && energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
        fn_111_C110(energy, context);
    }
    s16 copy;
    fn_111_C3AC(&copy, event);
    fn_111_C3A4(object + 4, &copy, context);
}
