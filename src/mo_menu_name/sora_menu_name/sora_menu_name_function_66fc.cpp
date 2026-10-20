#pragma force_active on
struct MenuState {
    unsigned char padding[0xD0];
    int state;
};

struct MenuName {
    unsigned char padding0[0x9C];
    int result;
    unsigned char padding1[0x408 - 0xA0];
    MenuState* state;
    unsigned char padding2[0x474 - 0x40C];
    bool flag;
};

extern "C" int fn_16_66FC(MenuName* self) {
    int state = self->state->state;
    if (state == 1)
        return self->result;

    self->flag = true;
    int result = 0x17;
    if (state == 6)
        result = 0x16;
    return result;
}
