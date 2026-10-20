#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

class soModuleAccesser;

extern "C" {
void fn_101_10BD8(soKineticEnergy*, soModuleAccesser*);
void fn_101_10CC0(short*, const short*);
void fn_101_10CB8(void*, short*, soModuleAccesser*);
}

extern "C" void fn_101_10C28(void* energy, const short* mask,
                             soModuleAccesser* accesser) {
    soKineticEnergy* e =
        reinterpret_cast<soKineticEnergy*>(
            static_cast<unsigned char*>(energy) + 0x0C);

    if ((*mask & 0x4) != 0 &&
        e->isEnable() == true &&
        reinterpret_cast<unsigned char*>(e)[6] == 0) {
        fn_101_10BD8(e, accesser);
    }

    short copy;
    fn_101_10CC0(&copy, mask);
    fn_101_10CB8(static_cast<unsigned char*>(energy) + 4, &copy, accesser);
}
