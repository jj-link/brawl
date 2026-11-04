#pragma force_active on
#pragma fp_contract on
#pragma fp_peephole on
extern "C" float randf__Fv();

struct Foo {
    char pad[0x4C];
    unsigned char f4C;
    unsigned char f4D;
    unsigned char f4E;
    unsigned char f4F;
    unsigned int f50;
    unsigned int f54;
    unsigned int f58;
    unsigned int f5C;
};

extern "C" void fn_40_1530C(Foo* self) {
    self->f4C = 1;
    unsigned int a = self->f50;
    self->f4E = 1;
    self->f5C = 0;
    float r = randf__Fv();
    unsigned int b = self->f54;
    float diff = (float)(b - a);
    self->f58 = a + (unsigned int)(diff * r);
}
