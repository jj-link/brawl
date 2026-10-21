#pragma force_active on

struct Obj {
    unsigned char pad000[0x350];
    unsigned int unk350;
    unsigned char pad354[0x2C];
    unsigned char unk380;
    unsigned char pad381[3];
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
};

extern "C" void fn_800C6E9C(Obj* self, int a, int b, int c) {
    self->unk380 = 0;
    self->unk384 = a;
    self->unk388 = 0;
    self->unk38C = b;
    self->unk390 = c;
    self->unk350 = 4;
}
