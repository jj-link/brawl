#include <types.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on
#pragma optimization_level 2
#pragma scheduling off
#pragma optimize_for_size on

extern "C" void fn_27_332B3C(soKineticEnergy*, soModuleAccesser*);

extern "C" void fn_27_3326C4(soKineticEnergy* energy, soModuleAccesser* accesser) {
    unsigned char states[14];
    if (accesser->getKineticModule().getKineticType() <= 99) {
        fn_27_332B3C(energy, accesser);
        return;
    }
    if (!energy->isEnable() || reinterpret_cast<u8*>(energy)[6] == 1u) return;
    switch (accesser->getKineticModule().getKineticType()) {
    case 100: { __memclr(&states[13], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 101: { __memclr(&states[12], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 102: { __memclr(&states[11], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 103: { __memclr(&states[10], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 104: { __memclr(&states[9], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 105: { __memclr(&states[8], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 106: { __memclr(&states[7], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 107: { __memclr(&states[6], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 108: { __memclr(&states[5], 1); fn_27_332B3C(energy, accesser); break; }
    case 109: { __memclr(&states[4], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 110: { __memclr(&states[3], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 111: { __memclr(&states[2], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 112: { __memclr(&states[1], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    case 113: { __memclr(&states[0], 1); if (static_cast<u32>(energy->isEnable()) == 1u && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    }
}
