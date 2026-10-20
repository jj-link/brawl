#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_114_FFB0(soKineticEnergy* energy, void* source);
extern "C" s16* fn_114_10520(s16* destination, const s16* source);
extern "C" s32 fn_114_10090(void* object, s16* data, void* source);

struct LucasFlagHeader {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 suspension;
};

extern "C" void fn_114_10000(void* object, s16* param, void* source) {
    LucasFlagHeader* header = reinterpret_cast<LucasFlagHeader*>(static_cast<char*>(object) + 0xc);
    if (param[0] & 1) {
        bool flag = header->flag;
        if (flag == true && header->suspension == 0) {
            fn_114_FFB0(reinterpret_cast<soKineticEnergy*>(header), source);
        }
    }
    s16 buffer[4];
    fn_114_10520(buffer, param);
    fn_114_10090(static_cast<char*>(object) + 4, buffer, source);
}
