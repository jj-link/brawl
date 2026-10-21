#include <so/so_enable.h>
#pragma force_active on

class soModuleAccesser;

struct PikachuMediatorEnergy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    bool suspended;
};

struct PikachuPoolFlag {
    short mask;
};

extern "C" {
void fn_98_CFC8(PikachuMediatorEnergy*, soModuleAccesser*);
PikachuPoolFlag* fn_98_E208(PikachuPoolFlag*, const PikachuPoolFlag&);
void fn_98_D25C(void*, const PikachuPoolFlag&, soModuleAccesser*);
}

extern "C" void fn_98_D1CC(void* pool, const PikachuPoolFlag& flags,
                          soModuleAccesser* accesser) {
    char* base = static_cast<char*>(pool);
    PikachuMediatorEnergy* energy =
        reinterpret_cast<PikachuMediatorEnergy*>(base + 0xc);

    if ((flags.mask & 1) && energy->enabled.isEnable() == true &&
        !energy->suspended) {
        fn_98_CFC8(energy, accesser);
    }

    PikachuPoolFlag copy;
    fn_98_E208(&copy, flags);
    fn_98_D25C(base + 4, copy, accesser);
}
