#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" {
void fn_101_10580(soKineticEnergy*, soModuleAccesser*);
void fn_101_10CC0(short*, const short*);
void fn_101_10660(void*, const short*, soModuleAccesser*);
}

extern "C" void fn_101_105D0(unsigned char* object, const short* mask, soModuleAccesser* accesser) {
    soKineticEnergy* energy = reinterpret_cast<soKineticEnergy*>(object + 0xC);
    if ((*mask & 1) && energy->isEnable() == true &&
        reinterpret_cast<unsigned char*>(energy)[6] == 0) {
        fn_101_10580(energy, accesser);
    }

    short copy;
    fn_101_10CC0(&copy, mask);
    fn_101_10660(object + 4, &copy, accesser);
}
