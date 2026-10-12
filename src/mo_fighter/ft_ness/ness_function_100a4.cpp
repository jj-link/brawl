#include <so/kinetic/so_kinetic_energy.h>

extern "C" {
soKineticEnergy* fn_101_10C10(void*, int);
soKineticEnergy* fn_101_10B28(void*, int);
soKineticEnergy* fn_101_10A40(void*, int);
soKineticEnergy* fn_101_10958(void*, int);
soKineticEnergy* fn_101_10870(void*, int);
soKineticEnergy* fn_101_10788(void*, int);
soKineticEnergy* fn_101_106A0(void*, int);
soKineticEnergy* fn_101_105B8(void*, int);
void fn_101_10BD8(soKineticEnergy*, soModuleAccesser*);
void fn_101_10AF0(soKineticEnergy*, soModuleAccesser*);
void fn_101_10A08(soKineticEnergy*, soModuleAccesser*);
void fn_101_10920(soKineticEnergy*, soModuleAccesser*);
void fn_101_10838(soKineticEnergy*, soModuleAccesser*);
void fn_101_10750(soKineticEnergy*, soModuleAccesser*);
void fn_101_10668(soKineticEnergy*, soModuleAccesser*);
void fn_101_10580(soKineticEnergy*, soModuleAccesser*);
}

// Each concrete energy array has one slot. The suspension field is a full
// byte in these concrete energies; preserve its nonzero test rather than
// interpreting only the bit exposed by soSuspendable.
extern "C" void fn_101_100A4(unsigned char* energies, soModuleAccesser* accesser) {
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_101_10C10(energies + 0x208, i);
        if (energy->isEnable() == true && reinterpret_cast<unsigned char*>(energy)[6] == 0) {
            fn_101_10BD8(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_101_10B28(energies + 0x1CC, i);
        if (energy->isEnable() == true && reinterpret_cast<unsigned char*>(energy)[6] == 0) {
            fn_101_10AF0(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_101_10A40(energies + 0x180, i);
        if (energy->isEnable() == true && reinterpret_cast<unsigned char*>(energy)[6] == 0) {
            fn_101_10A08(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_101_10958(energies + 0x138, i);
        if (energy->isEnable() == true && reinterpret_cast<unsigned char*>(energy)[6] == 0) {
            fn_101_10920(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_101_10870(energies + 0xF0, i);
        if (energy->isEnable() == true && reinterpret_cast<unsigned char*>(energy)[6] == 0) {
            fn_101_10838(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_101_10788(energies + 0x98, i);
        if (energy->isEnable() == true && reinterpret_cast<unsigned char*>(energy)[6] == 0) {
            fn_101_10750(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_101_106A0(energies + 0x64, i);
        if (energy->isEnable() == true && reinterpret_cast<unsigned char*>(energy)[6] == 0) {
            fn_101_10668(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_101_105B8(energies + 0x8, i);
        if (energy->isEnable() == true && reinterpret_cast<unsigned char*>(energy)[6] == 0) {
            fn_101_10580(energy, accesser);
        }
    }
}
