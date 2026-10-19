#pragma force_active on
extern "C" void fn_27_C7438(void*, int);

struct Unk_41_2842C {
    unsigned char unk00[0x10];
    int unk10;
    unsigned char unk14;
};

extern "C" Unk_41_2842C* fn_41_2842C(Unk_41_2842C* self, int p2, int p3) {
    fn_27_C7438(self, p3);
    self->unk10 = p2;
    self->unk14 = 0;
    return self;
}
