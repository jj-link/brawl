#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

struct AiEnvironmentView {
    u8 pad[0x40];
    u32 flags;
};

struct AiFighterState {
    u8 pad0[0x50];
    u32 flags;
    u8 pad54[0x68];
    AiEnvironmentView* environment;
    u8 padC0[0xFA];
    u8 state;
};

extern "C" AiFighterState* fn_27_1F1F58(s8* fighterId);

extern "C" u32 fn_27_20B5AC(void*, s8* fighterId) {
    AiFighterState* fighter = fn_27_1F1F58(fighterId);
    u32 flags = fighter->flags;

    if ((!(flags & 1) && !(fighter->environment->flags & 0x20000)) ||
        (u8)(fighter->state + 0xFA) <= 1) {
        return true;
    }

    return ((flags >> 1) & 1) ^ 1;
}
