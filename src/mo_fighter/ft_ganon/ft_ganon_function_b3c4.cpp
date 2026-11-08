#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>
#include <StaticAssert.h>
#pragma force_active on

class soModuleAccesser;

extern "C" {
soKineticEnergy* fn_109_BEF8(void*, int);
soKineticEnergy* fn_109_BE10(void*, int);
soKineticEnergy* fn_109_BD28(void*, int);
soKineticEnergy* fn_109_BC40(void*, int);
soKineticEnergy* fn_109_BB58(void*, int);
soKineticEnergy* fn_109_BA70(void*, int);
soKineticEnergy* fn_109_B9C0(void*, int);
soKineticEnergy* fn_109_B8D8(void*, int);
void fn_109_BEC0(soKineticEnergy*, soModuleAccesser*);
void fn_109_BDD8(soKineticEnergy*, soModuleAccesser*);
void fn_109_BCF0(soKineticEnergy*, soModuleAccesser*);
void fn_109_BC08(soKineticEnergy*, soModuleAccesser*);
void fn_109_BB20(soKineticEnergy*, soModuleAccesser*);
void fn_109_E470(soKineticEnergy*, soModuleAccesser*);
void fn_109_B988(soKineticEnergy*, soModuleAccesser*);
void fn_109_B8A0(soKineticEnergy*, soModuleAccesser*);
}

extern "C" void fn_109_B3C4(u8* object, soModuleAccesser* accesser) {
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* entry = fn_109_BEF8(object + 0x208, i);
        if (entry->isEnable() == true && reinterpret_cast<u8*>(entry)[6] == 0)
            fn_109_BEC0(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* entry = fn_109_BE10(object + 0x1CC, i);
        if (entry->isEnable() == true && reinterpret_cast<u8*>(entry)[6] == 0)
            fn_109_BDD8(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* entry = fn_109_BD28(object + 0x180, i);
        if (entry->isEnable() == true && reinterpret_cast<u8*>(entry)[6] == 0)
            fn_109_BCF0(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* entry = fn_109_BC40(object + 0x138, i);
        if (entry->isEnable() == true && reinterpret_cast<u8*>(entry)[6] == 0)
            fn_109_BC08(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* entry = fn_109_BB58(object + 0xF0, i);
        if (entry->isEnable() == true && reinterpret_cast<u8*>(entry)[6] == 0)
            fn_109_BB20(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* entry = fn_109_BA70(object + 0x98, i);
        if (entry->isEnable() == true && reinterpret_cast<u8*>(entry)[6] == 0)
            fn_109_E470(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* entry = fn_109_B9C0(object + 0x64, i);
        if (entry->isEnable() == true && reinterpret_cast<u8*>(entry)[6] == 0)
            fn_109_B988(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        soKineticEnergy* entry = fn_109_B8D8(object + 0x8, i);
        if (entry->isEnable() == true && reinterpret_cast<u8*>(entry)[6] == 0)
            fn_109_B8A0(entry, accesser);
    }
}