#pragma force_active on
struct State {
    unsigned char padding_00[0x0F];
    unsigned char kind;
    bool active;
    unsigned char unused_high : 4;
    unsigned char flag : 1;
    unsigned char unused_low : 3;
    unsigned char padding_12[0x15E];
    unsigned char status;
};

extern "C" bool fn_27_115B34(const State* state) {
    if (static_cast<bool>(state->flag) == true) {
        return true;
    }

    if (state->active) {
        return true;
    }

    if (state->kind == 3 && state->status == 1) {
        return true;
    }

    return false;
}
