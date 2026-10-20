#pragma force_active on
struct State {
    unsigned char padding[0x304];
    float values[1];
};

struct Update {
    unsigned char padding[0x2C];
    unsigned int index;
    float value;
};

extern "C" void fn_27_2D7B58(State* state, const Update* update) {
    float& current = state->values[update->index];
    if (current < update->value) {
        current = update->value;
    }
}
