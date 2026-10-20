#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
struct AiFighterState;

extern "C" {
AiFighterState* fn_27_1F1F58(s8* fighterId);
s32 fn_27_1F2D0C(s8* fighterId);
void* fn_27_1F218C(s32 param);
}

struct AiFighterState {
    /* 0x000 */ char pad0[0xAC];
    /* 0x0AC */ s32 unkAC;
};

extern "C" u8 fn_27_21F0B4(s8* fighterId) {
    if (fn_27_1F2D0C(fighterId) != 0) {
        return *(u8*)((u8*)fn_27_1F218C(fn_27_1F1F58(fighterId)->unkAC) + 0x10);
    }
    return *(u8*)((u8*)fn_27_1F218C(0) + 0x10);
}
