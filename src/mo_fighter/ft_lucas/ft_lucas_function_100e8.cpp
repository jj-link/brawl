#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_114_10098(soKineticEnergy* energy, void* source);
extern "C" s16* fn_114_10520(s16* destination, const s16* source);
extern "C" s32 fn_114_10178(char* object, s16* state, void* accesser);

struct LucasFlagHeader {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 suspension;
};

extern "C" void fn_114_100E8(char* object, s16* state, void* source) {
    LucasFlagHeader* header =
        reinterpret_cast<LucasFlagHeader*>(object + 0xc);
    if ((*state & 1) != 0) {
        bool flag = header->flag;
        if (flag == true && header->suspension == 0) {
            fn_114_10098(reinterpret_cast<soKineticEnergy*>(header), source);
        }
    }
    s16 value;
    fn_114_10520(&value, state);
    fn_114_10178(object + 4, &value, source);
}
