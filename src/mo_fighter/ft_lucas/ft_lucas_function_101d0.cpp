#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>
#pragma force_active on

struct LucasEnergyFlagBytes {
    u8 pad[5];
    u8 enabled : 1;
    u8 rest : 7;
    u8 suspension;
};

extern "C" void fn_114_10180(soKineticEnergy* energy, void* source);
extern "C" s16* fn_114_10520(s16* destination, const s16* source);
extern "C" void fn_114_10260(void* object, const s16* value, void* source);

extern "C" void fn_114_101D0(void* object, const s16* flags, void* source) {
    char* base = static_cast<char*>(object);
    const LucasEnergyFlagBytes* energy =
        reinterpret_cast<const LucasEnergyFlagBytes*>(base + 0xc);

    if ((*flags & 2) != 0) {
        bool enabled = energy->enabled;
        if (enabled == true && energy->suspension == 0) {
            fn_114_10180(reinterpret_cast<soKineticEnergy*>(base + 0xc), source);
        }
    }

    s16 value;
    fn_114_10520(&value, flags);
    fn_114_10260(base + 4, &value, source);
}
