#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>

extern "C" soKineticEnergy* fn_114_10470(void* object, int index);
extern "C" soKineticEnergy* fn_114_10388(void* object, int index);
extern "C" soKineticEnergy* fn_114_102A0(void* object, int index);
extern "C" soKineticEnergy* fn_114_101B8(void* object, int index);
extern "C" soKineticEnergy* fn_114_100D0(void* object, int index);
extern "C" soKineticEnergy* fn_114_FFE8(void* object, int index);
extern "C" soKineticEnergy* fn_114_FF00(void* object, int index);
extern "C" soKineticEnergy* fn_114_FE18(void* object, int index);
extern "C" void fn_114_10438(soKineticEnergy* energy, void* source);
extern "C" void fn_114_10350(soKineticEnergy* energy, void* source);
extern "C" void fn_114_10268(soKineticEnergy* energy, void* source);
extern "C" void fn_114_10180(soKineticEnergy* energy, void* source);
extern "C" void fn_114_10098(soKineticEnergy* energy, void* source);
extern "C" void fn_114_FFB0(soKineticEnergy* energy, void* source);
extern "C" void fn_114_FEC8(soKineticEnergy* energy, void* source);
extern "C" void fn_114_FDE0(soKineticEnergy* energy, void* source);

// The original tests the entire suspension byte, not only its leading bit.
static inline bool hasNoSuspensionByte(const soKineticEnergy* energy) {
    return reinterpret_cast<const u8*>(energy)[6] == 0;
}

extern "C" void fn_114_F904(void* object, void* source) {
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_114_10470(static_cast<char*>(object) + 0x208, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_114_10438(energy, source);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_114_10388(static_cast<char*>(object) + 0x1cc, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_114_10350(energy, source);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_114_102A0(static_cast<char*>(object) + 0x180, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_114_10268(energy, source);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_114_101B8(static_cast<char*>(object) + 0x138, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_114_10180(energy, source);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_114_100D0(static_cast<char*>(object) + 0xf0, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_114_10098(energy, source);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_114_FFE8(static_cast<char*>(object) + 0x98, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_114_FFB0(energy, source);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_114_FF00(static_cast<char*>(object) + 0x64, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_114_FEC8(energy, source);
        }
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* energy = fn_114_FE18(static_cast<char*>(object) + 8, i);
        if (energy->isEnable() == true && hasNoSuspensionByte(energy)) {
            fn_114_FDE0(energy, source);
        }
    }
}
