#pragma force_active on

struct S {
    unsigned char pad[0x1c];
    signed char f;
    unsigned char pad2[0x8];
    unsigned char* o;
};

extern "C" void fn_802DE79C(S* self, signed char value) {
    unsigned char* p = self->o;
    self->f = value;
    if (p != 0) {
        p[0x12] = value;
    }
}
