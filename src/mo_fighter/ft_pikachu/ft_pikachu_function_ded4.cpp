#pragma force_active on
class soModuleAccesser;

struct PikachuPoolFlag {
    short value;
    char rest[6];
};

struct PikachuEnergyBits {
    unsigned char pad[5];
    unsigned char high : 1;
    unsigned char low : 7;
    unsigned char tail;
};

extern "C" {
PikachuPoolFlag* fn_98_E208(PikachuPoolFlag*, const PikachuPoolFlag&);
void fn_98_DCD0(unsigned char*, soModuleAccesser*);
void fn_98_DF64(unsigned char*, PikachuPoolFlag*, soModuleAccesser*);
}

extern "C" void fn_98_DED4(unsigned char* mediator, const PikachuPoolFlag* flags, soModuleAccesser* accesser) {
    unsigned char* energy = mediator + 0xC;
    if (flags->value & 0x8) {
        bool enabled = static_cast<PikachuEnergyBits*>(static_cast<void*>(energy))->high;
        if (enabled == true) {
            if (energy[6] == 0) {
                fn_98_DCD0(energy, accesser);
            }
        }
    }
    PikachuPoolFlag copy;
    fn_98_E208(&copy, *flags);
    fn_98_DF64(mediator + 4, &copy, accesser);
}
