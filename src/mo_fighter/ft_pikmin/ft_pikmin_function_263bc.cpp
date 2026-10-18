#pragma force_active on
extern "C" {
extern unsigned char lbl_113_data_B078[0x3C];

struct PikminState {
    void* cursor;
    unsigned char flag;
    void* base;
};

void fn_113_263BC(PikminState* state) {
    state->flag = 0;
    state->base = lbl_113_data_B078;
    state->cursor = &lbl_113_data_B078[8];
}
}
