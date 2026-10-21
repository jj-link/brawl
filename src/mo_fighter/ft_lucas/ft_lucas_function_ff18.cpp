#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>
#pragma force_active on

struct LucasEnergyFlagBytes {
    u8 pad[5];
    u8 suspended : 1;
    u8 rest : 7;
    u8 tail;
};

extern "C" void fn_114_FEC8(soKineticEnergy* energy, void* source);
extern "C" s16* fn_114_10520(s16* destination, const s16* source);
extern "C" void fn_114_FFA8(void* object, const s16* value, void* source);

extern "C" void fn_114_FF18(void* object, const s16* flags, void* source) {
    char* base = static_cast<char*>(object);
    const LucasEnergyFlagBytes* energy =
        reinterpret_cast<const LucasEnergyFlagBytes*>(base + 0xc);

    if ((*flags & 0x1) != 0) {
        bool suspended = energy->suspended;
        if (suspended == true && energy->tail == 0) {
            fn_114_FEC8(reinterpret_cast<soKineticEnergy*>(base + 0xc), source);
        }
    }

    s16 value;
    fn_114_10520(&value, flags);
    fn_114_FFA8(base + 4, &value, source);
}
