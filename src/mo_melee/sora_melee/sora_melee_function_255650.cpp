#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct GameState {
    char pad0[8];
    u8 mode : 6;
    u8 modeLow : 2;
    char pad9[0x11];
    u16 kind;
    char pad1c[0x47];
    u8 flag63;
    u8 flag64;
    char pad65[3];
    int value68;
    int value6c;
};
struct GameGlobal { char pad0[8]; GameState* state; };
struct Switch {
    char pad0[0x24];
    u8 flag : 1;
    u8 rest : 7;
};
extern "C" {
extern GameGlobal* g_GameGlobal;
Switch* getInstance__8ipSwitchFv();
void fn_8004ACDC(Switch*, int);
void fn_8004AC50(Switch*, int);
}
static inline bool isAllowed(u32 mode) {
    switch (mode) {
    case 13: case 15: case 17: case 19: case 21: case 22:
    case 25: case 27: case 29: case 30: case 31: case 32: case 33:
        return false;
    default:
        return true;
    }
}
extern "C" void fn_27_255650() {
    GameState* state = g_GameGlobal->state;
    bool special = false;
    if (state->kind == 0x34 && state->flag63 == 0 && state->flag64 == 0)
        special = true;
    u8 value = 0;
    if (special)
        value = state->value68 + state->value6c * 2;
    if (getInstance__8ipSwitchFv()->flag) {
        fn_8004ACDC(getInstance__8ipSwitchFv(), value);
        Switch* sw = getInstance__8ipSwitchFv();
        sw->flag = false;
        return;
    }
    if (isAllowed(state->mode)) {
        getInstance__8ipSwitchFv();
        fn_8004AC50(getInstance__8ipSwitchFv(), value);
    }
}
