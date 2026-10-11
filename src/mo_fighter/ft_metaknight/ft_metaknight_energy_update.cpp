#include <so/kinetic/so_kinetic_energy.h>

extern "C" soKineticEnergy* fn_111_C2FC(void* array, int index);
extern "C" soKineticEnergy* fn_111_C060(void* array, int index);
extern "C" soKineticEnergy* fn_111_BDC4(void* array, int index);
extern "C" soKineticEnergy* fn_111_BB28(void* array, int index);
extern "C" soKineticEnergy* fn_111_B88C(void* array, int index);
extern "C" soKineticEnergy* fn_111_B5F0(void* array, int index);
extern "C" soKineticEnergy* fn_111_B360(void* array, int index);
extern "C" soKineticEnergy* fn_111_B0C8(void* array, int index);
extern "C" void fn_111_C110(soKineticEnergy*, void* context);
extern "C" void fn_111_BE74(soKineticEnergy*, void* context);
extern "C" void fn_111_BBD8(soKineticEnergy*, void* context);
extern "C" void fn_111_B93C(soKineticEnergy*, void* context);
extern "C" void fn_111_B6A0(soKineticEnergy*, void* context);
extern "C" void fn_111_B410(soKineticEnergy*, void* context);
extern "C" void fn_111_B178(soKineticEnergy*, void* context);
extern "C" void fn_111_AEE8(soKineticEnergy*, void* context);

extern "C" void fn_111_A870(void* object, void* context) {
    u8* state = static_cast<u8*>(object);
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_111_C2FC(state + 0x208, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_111_C110(energy, context);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_111_C060(state + 0x1CC, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_111_BE74(energy, context);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_111_BDC4(state + 0x180, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_111_BBD8(energy, context);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_111_BB28(state + 0x138, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_111_B93C(energy, context);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_111_B88C(state + 0xF0, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_111_B6A0(energy, context);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_111_B5F0(state + 0x98, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_111_B410(energy, context);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_111_B360(state + 0x64, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_111_B178(energy, context);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_111_B0C8(state + 8, i);
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
            fn_111_AEE8(energy, context);
        }
    }
}
