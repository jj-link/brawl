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
void fn_98_D264(PikachuMediatorEnergy*, soModuleAccesser*);
PikachuPoolFlag* fn_98_E208(PikachuPoolFlag*, const PikachuPoolFlag&);
void fn_98_D4F4(void*, const PikachuPoolFlag&, soModuleAccesser*);
}

extern "C" void fn_98_D464(void* pool, const PikachuPoolFlag& flags,
                          soModuleAccesser* accesser) {
    char* data = static_cast<char*>(pool);
    PikachuMediatorEnergy* energy =
        reinterpret_cast<PikachuMediatorEnergy*>(data + 0xc);

    if ((flags.mask & 1) && energy->enabled.isEnable() == true &&
        !energy->suspended)
        fn_98_D264(energy, accesser);

    PikachuPoolFlag copy;
    fn_98_E208(&copy, flags);
    fn_98_D4F4(data + 4, copy, accesser);
}
