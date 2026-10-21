#pragma force_active on
struct GameState {
    unsigned char padding[0x1B];
    unsigned char value;
};

struct GameGlobal {
    unsigned char padding[0x38];
    GameState* state;
};

extern GameGlobal* g_GameGlobal;

extern "C" void fn_8014FDE0(unsigned char value) {
    g_GameGlobal->state->value = value;
}
