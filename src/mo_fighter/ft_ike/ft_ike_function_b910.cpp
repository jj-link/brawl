#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>
#pragma force_active on

extern "C" {
soKineticEnergy* fn_119_C47C(void*, int);
soKineticEnergy* fn_119_C394(void*, int);
soKineticEnergy* fn_119_C2AC(void*, int);
soKineticEnergy* fn_119_C1C4(void*, int);
soKineticEnergy* fn_119_C0DC(void*, int);
soKineticEnergy* fn_119_BFF4(void*, int);
soKineticEnergy* fn_119_BF0C(void*, int);
soKineticEnergy* fn_119_BE24(void*, int);

void fn_119_C444(soKineticEnergy*, soModuleAccesser*);
void fn_119_C35C(soKineticEnergy*, soModuleAccesser*);
void fn_119_C274(soKineticEnergy*, soModuleAccesser*);
void fn_119_C18C(soKineticEnergy*, soModuleAccesser*);
void fn_119_C0A4(soKineticEnergy*, soModuleAccesser*);
void fn_119_BFBC(soKineticEnergy*, soModuleAccesser*);
void fn_119_BED4(soKineticEnergy*, soModuleAccesser*);
void fn_119_BDEC(soKineticEnergy*, soModuleAccesser*);
}

static inline bool hasNoSuspensionByte(const soKineticEnergy* energy) {
    return reinterpret_cast<const u8*>(energy)[6] == 0;
}

extern "C" void fn_119_B910(void* object, soModuleAccesser* accesser) {
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_119_C47C(static_cast<char*>(object) + 0x208, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_119_C444(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_119_C394(static_cast<char*>(object) + 0x1CC, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_119_C35C(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_119_C2AC(static_cast<char*>(object) + 0x180, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_119_C274(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_119_C1C4(static_cast<char*>(object) + 0x138, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_119_C18C(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_119_C0DC(static_cast<char*>(object) + 0xF0, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_119_C0A4(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_119_BFF4(static_cast<char*>(object) + 0x98, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_119_BFBC(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_119_BF0C(static_cast<char*>(object) + 0x64, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_119_BED4(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_119_BE24(static_cast<char*>(object) + 8, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_119_BDEC(energy, accesser);
        }
    }
}
