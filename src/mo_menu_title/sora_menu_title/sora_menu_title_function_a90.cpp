#pragma force_active on
struct MenuTitle {
    unsigned char padding[0x4C];
    unsigned int state;
};

extern "C" bool fn_24_A90(MenuTitle* self) {
    return self->state - 3 <= 1;
}
