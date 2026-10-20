#pragma force_active on
class soModuleAccesser;

struct PikachuPoolFlag {
    short value;
};

struct PikachuEnergyBits {
    unsigned char on : 1;
    unsigned char pad : 7;
};

extern "C" {
PikachuPoolFlag* fn_98_E208(PikachuPoolFlag*, const PikachuPoolFlag&);
void fn_98_D798(void*, soModuleAccesser*);
void fn_98_DA2C(void*, PikachuPoolFlag*, soModuleAccesser*);
}

extern "C" void fn_98_D99C(unsigned char* self, PikachuPoolFlag* flags, soModuleAccesser* accesser) {
    unsigned char* energy = self + 0xc;
    if (flags->value & 2) {
        PikachuEnergyBits* bits = reinterpret_cast<PikachuEnergyBits*>(energy + 5);
        bool flag = bits->on;
        if (flag == true && energy[6] == 0) {
            fn_98_D798(energy, accesser);
        }
    }
    PikachuPoolFlag local;
    fn_98_E208(&local, *flags);
    fn_98_DA2C(self + 4, &local, accesser);
}
