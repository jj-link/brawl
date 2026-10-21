#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct State {
    u8 pad0[0x8CD];
    u8 active;
    u8 count;
    u8 pad8CF[0xB4];
    u8 value;
    u16 accumulated;
};

extern struct State* lbl_804F6810[];

void fn_802171F4(int index) {
    u16 capped;
    struct State* state;
    u16 value;
    u32 final_value;

    state = lbl_804F6810[index];
    value = state->value * 9;
    value += (u16)((u32)(state->accumulated * 100) >> 1);
    value /= 10;
    capped = value > 100U ? 100 : value;

    state->value = capped;
    state->accumulated = 0;
    final_value = capped;

    if (state->active != 0) {
        if (final_value > 85U) {
            state->active = 0;
            state->count = 0;
            return;
        }
        if (final_value > 80U) {
            if (++state->count >= 20U) {
                state->active = 0;
                state->count = 0;
            }
        }
    } else {
        if (final_value < 75U) {
            state->active = 1;
            state->count = 0;
            return;
        }
        if (final_value < 80U) {
            if (++state->count >= 1U) {
                state->active = 1;
                state->count = 0;
            }
        }
    }
}
