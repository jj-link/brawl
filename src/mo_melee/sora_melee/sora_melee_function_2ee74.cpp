#pragma force_active on
struct Inner {
    unsigned char pad[0x73];
    unsigned char unused : 4;
    unsigned char flag : 1;
    unsigned char rest : 3;
};

struct Object {
    unsigned int unk0;
    Inner* inner;
    unsigned char pad[0x34];
    unsigned int flag : 1;
    unsigned int rest : 31;
};

extern "C" void fn_27_2EE74(Object* self, unsigned int value, unsigned int mode) {
    self->inner->flag = value;
    if (mode == 1) {
        self->flag = value;
    }
}
