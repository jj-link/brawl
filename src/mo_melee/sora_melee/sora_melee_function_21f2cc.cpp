#include <types.h>
#pragma force_active on

struct RoData {
    char pad0[0x40];
    float f40;
    char pad44[0x10];
    float f54;
    char pad58[0x10];
    float f68;
};

struct AiFighterState {
    char pad0[0x6C];
    float f6C;
    char pad70[0x3C];
    s32 unkAC;
};

struct Thing {
    char pad0[0x18];
    float f18;
};

extern "C" AiFighterState* fn_27_1F1F58(s8* fighterId);
extern "C" s32 fn_27_1F2D0C(s8* fighterId);
extern "C" void* fn_27_1F218C(s32 param);

extern "C" RoData lbl_27_rodata_3290;

extern "C" float fn_27_21F2CC(s8* fighterId) {
    RoData* rd = &lbl_27_rodata_3290;
    AiFighterState* state = fn_27_1F1F58(fighterId);
    if (fn_27_1F2D0C(fighterId) != 0) {
        return (rd->f40 + rd->f54 * state->f6C) * (((Thing*)fn_27_1F218C(state->unkAC))->f18 - rd->f68);
    }
    return (rd->f40 + rd->f54 * state->f6C) * (((Thing*)fn_27_1F218C(0))->f18 - rd->f68);
}
