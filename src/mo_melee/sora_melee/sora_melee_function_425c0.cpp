#pragma force_active on
struct State {
    unsigned char pad00[0x20];
    int state;
    int pad24;
    int count;
    unsigned char pad2C[5];
    unsigned char flag31;
    unsigned char flag32;
};

extern "C" void fn_27_425C0(State* self) {
    self->flag31 = 1;

    if (self->flag31 == 1 || self->flag31 != 0) {
        self->state = 2;
    } else if (self->flag32 == 1 || self->count != 0) {
        self->state = 1;
    } else {
        self->state = 0;
    }
}
