#pragma force_active on
struct Title {
    unsigned char pad0[0x2C];
    unsigned char flags;
    unsigned char pad1[0x1D0 - 0x2D];
    unsigned char state;
    unsigned char pad2[7];
    int timer;
};

extern "C" void fn_24_3CC(Title* self, int mode) {
    self->flags &= ~2;
    switch (mode) {
    case 0:
        self->state = 0;
        break;
    case 2:
    default:
        self->state = 1;
        break;
    case 3:
        self->state = 2;
        break;
    case 4:
        self->state = 3;
        break;
    }
    self->timer = 0;
}
