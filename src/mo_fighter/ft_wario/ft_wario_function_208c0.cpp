#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>
#pragma force_active on

extern "C" {
soKineticEnergy* fn_110_C614(void*, int);
soKineticEnergy* fn_110_C52C(void*, int);
soKineticEnergy* fn_110_C444(void*, int);
soKineticEnergy* fn_110_C35C(void*, int);
soKineticEnergy* fn_110_C274(void*, int);
soKineticEnergy* fn_110_C18C(void*, int);
soKineticEnergy* fn_110_C0A4(void*, int);
soKineticEnergy* fn_110_BFBC(void*, int);

void fn_110_C5DC(soKineticEnergy*, soModuleAccesser*);
void fn_110_C4F4(soKineticEnergy*, soModuleAccesser*);
void fn_110_C40C(soKineticEnergy*, soModuleAccesser*);
void fn_110_C324(soKineticEnergy*, soModuleAccesser*);
void fn_110_C23C(soKineticEnergy*, soModuleAccesser*);
void fn_110_C154(soKineticEnergy*, soModuleAccesser*);
void fn_110_C06C(soKineticEnergy*, soModuleAccesser*);
void fn_110_BF84(soKineticEnergy*, soModuleAccesser*);
}

static inline bool hasNoSuspensionByte(const soKineticEnergy* energy) {
    return reinterpret_cast<const u8*>(energy)[6] == 0;
}

extern "C" void fn_110_208C0(void* object, soModuleAccesser* accesser) {
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_110_C614(static_cast<char*>(object) + 0x208, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_110_C5DC(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_110_C52C(static_cast<char*>(object) + 0x1CC, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_110_C4F4(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_110_C444(static_cast<char*>(object) + 0x180, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_110_C40C(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_110_C35C(static_cast<char*>(object) + 0x138, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_110_C324(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_110_C274(static_cast<char*>(object) + 0xF0, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_110_C23C(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_110_C18C(static_cast<char*>(object) + 0x98, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_110_C154(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_110_C0A4(static_cast<char*>(object) + 0x64, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_110_C06C(energy, accesser);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_110_BFBC(static_cast<char*>(object) + 8, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_110_BF84(energy, accesser);
        }
    }
}
