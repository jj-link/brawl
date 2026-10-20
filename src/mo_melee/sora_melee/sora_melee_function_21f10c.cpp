#include <types.h>
#pragma force_active on

struct AiFighterState {
    u8 pad0[0xAC];
    s32 unkAC;
};

extern "C" {
AiFighterState* fn_27_1F1F58(s8* fighterId);
s32 fn_27_1F2D0C(void);
void* fn_27_1F218C(s32 arg);
}

extern "C" f32 fn_27_21F10C(s8* fighterId) {
    if (fn_27_1F2D0C() != 0) {
        AiFighterState* state = fn_27_1F1F58(fighterId);
        void* ptr = fn_27_1F218C(state->unkAC);
        return *(f32*)((u8*)ptr + 4);
    } else {
        void* ptr = fn_27_1F218C(0);
        return *(f32*)((u8*)ptr + 4);
    }
}
