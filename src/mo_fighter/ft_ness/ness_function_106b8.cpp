#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" {
void fn_101_10668(soKineticEnergy*, soModuleAccesser*);
void fn_101_10CC0(short*, const short*);
void fn_101_10748(void*, short*, soModuleAccesser*);
}

struct NessEnergyFlagByte {
    unsigned char flag : 1;
    unsigned char rest : 7;
};

extern "C" void fn_101_106B8(unsigned char* self, const short* mask, soModuleAccesser* accesser) {
    unsigned char* energy = self + 0xC;
    if (mask[0] & 1) {
        NessEnergyFlagByte* f = reinterpret_cast<NessEnergyFlagByte*>(energy + 5);
        bool flag = f->flag;
        if (flag == true && energy[6] == 0) {
            fn_101_10668(reinterpret_cast<soKineticEnergy*>(energy), accesser);
        }
    }
    short local;
    fn_101_10CC0(&local, mask);
    fn_101_10748(self + 4, &local, accesser);
}
