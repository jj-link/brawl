#include <so/so_enable.h>

class soModuleAccesser;

// The pool entries share the kinetic-energy prefix, but suspension is a
// full byte in this mediator's instantiated energy types.
struct PikachuMediatorEnergy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    bool suspended;
};

extern "C" {
PikachuMediatorEnergy* fn_98_E158(void*, int);
PikachuMediatorEnergy* fn_98_DEBC(void*, int);
PikachuMediatorEnergy* fn_98_DC20(void*, int);
PikachuMediatorEnergy* fn_98_D984(void*, int);
PikachuMediatorEnergy* fn_98_D6E8(void*, int);
PikachuMediatorEnergy* fn_98_D44C(void*, int);
PikachuMediatorEnergy* fn_98_D1B4(void*, int);
PikachuMediatorEnergy* fn_98_CF18(void*, int);
void fn_98_DF6C(PikachuMediatorEnergy*, soModuleAccesser*);
void fn_98_DCD0(PikachuMediatorEnergy*, soModuleAccesser*);
void fn_98_DA34(PikachuMediatorEnergy*, soModuleAccesser*);
void fn_98_D798(PikachuMediatorEnergy*, soModuleAccesser*);
void fn_98_D4FC(PikachuMediatorEnergy*, soModuleAccesser*);
void fn_98_D264(PikachuMediatorEnergy*, soModuleAccesser*);
void fn_98_CFC8(PikachuMediatorEnergy*, soModuleAccesser*);
void fn_98_CD2C(PikachuMediatorEnergy*, soModuleAccesser*);
}

extern "C" void fn_98_C6B4(void* mediator, soModuleAccesser* accesser) {
    char* pools = static_cast<char*>(mediator);
    for (int i = 0; i < 1; ++i) {
        PikachuMediatorEnergy* energy = fn_98_E158(pools + 0x208, i);
        if (energy->enabled.isEnable() == true && !energy->suspended)
            fn_98_DF6C(energy, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikachuMediatorEnergy* energy = fn_98_DEBC(pools + 0x1cc, i);
        if (energy->enabled.isEnable() == true && !energy->suspended)
            fn_98_DCD0(energy, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikachuMediatorEnergy* energy = fn_98_DC20(pools + 0x180, i);
        if (energy->enabled.isEnable() == true && !energy->suspended)
            fn_98_DA34(energy, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikachuMediatorEnergy* energy = fn_98_D984(pools + 0x138, i);
        if (energy->enabled.isEnable() == true && !energy->suspended)
            fn_98_D798(energy, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikachuMediatorEnergy* energy = fn_98_D6E8(pools + 0xf0, i);
        if (energy->enabled.isEnable() == true && !energy->suspended)
            fn_98_D4FC(energy, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikachuMediatorEnergy* energy = fn_98_D44C(pools + 0x98, i);
        if (energy->enabled.isEnable() == true && !energy->suspended)
            fn_98_D264(energy, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikachuMediatorEnergy* energy = fn_98_D1B4(pools + 0x64, i);
        if (energy->enabled.isEnable() == true && !energy->suspended)
            fn_98_CFC8(energy, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikachuMediatorEnergy* energy = fn_98_CF18(pools + 0x8, i);
        if (energy->enabled.isEnable() == true && !energy->suspended)
            fn_98_CD2C(energy, accesser);
    }
}
