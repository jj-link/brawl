#include <so/kinetic/so_kinetic_energy.h>

extern "C" soKineticEnergy* fn_99_B7C4(void* array, int index);
extern "C" soKineticEnergy* fn_99_B6DC(void* array, int index);
extern "C" soKineticEnergy* fn_99_B5F4(void* array, int index);
extern "C" soKineticEnergy* fn_99_B50C(void* array, int index);
extern "C" soKineticEnergy* fn_99_B424(void* array, int index);
extern "C" soKineticEnergy* fn_99_B374(void* array, int index);
extern "C" soKineticEnergy* fn_99_B28C(void* array, int index);
extern "C" soKineticEnergy* fn_99_B1DC(void* array, int index);
extern "C" void fn_99_B78C(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_99_B6A4(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_99_B5BC(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_99_B4D4(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_99_C850(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_99_B33C(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_99_C914(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_99_B1A4(soKineticEnergy*, soModuleAccesser*);

extern "C" void fn_99_ACC8(void* object, soModuleAccesser* accesser) {
    u8* state = static_cast<u8*>(object);
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_99_B7C4(state + 0x208, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_99_B78C(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_99_B6DC(state + 0x1CC, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_99_B6A4(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_99_B5F4(state + 0x180, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_99_B5BC(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_99_B50C(state + 0x138, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_99_B4D4(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_99_B424(state + 0xF0, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_99_C850(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_99_B374(state + 0x98, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_99_B33C(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_99_B28C(state + 0x64, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_99_C914(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_99_B1DC(state + 8, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_99_B1A4(energy, accesser);
        }
    }
}
