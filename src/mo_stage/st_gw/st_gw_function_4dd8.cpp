#pragma force_active on
struct Flags {
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char b5 : 1;
    unsigned char b4 : 1;
    unsigned char b3 : 1;
    unsigned char b2 : 1;
    unsigned char b1 : 1;
    unsigned char b0 : 1;
};

struct Inner {
    char pad[0x54];
    Flags flags;
};

struct Outer {
    char pad0[0x194];
    float f194;
    unsigned char *p198;
    char pad1[0x8];
    Inner **p1a4;
};

extern const float lbl_63_rodata_54;

extern "C" void fn_63_4DD8(Outer *self)
{
    unsigned char idx = *self->p198;
    if (idx != 0xff) {
        Inner *o = self->p1a4[idx];
        o->flags.b7 = 0;
        o->flags.b4 = o->flags.b7;
        o->flags.b6 = o->flags.b4;
    }
    *self->p198 = 0xff;
    self->f194 = lbl_63_rodata_54;
}
