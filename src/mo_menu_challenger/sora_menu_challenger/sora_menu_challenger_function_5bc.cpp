#pragma force_active on
struct Challenger {
    unsigned char pad0[0x2C];
    unsigned char flags0 : 6;
    unsigned char flag : 1;
    unsigned char flags1 : 1;
    unsigned char pad1[0x27];
    unsigned int value;
    unsigned int timer;
};

extern "C" void fn_23_5BC(Challenger* self, unsigned int value) {
    self->value = value;
    self->flag = 0;
    self->timer = 0;
}
