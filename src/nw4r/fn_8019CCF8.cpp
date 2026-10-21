#pragma force_active on
extern "C" void fn_8019D618(void*);

struct Foo {
    char pad0[0x0C];
    float field_0C;
    char pad10[0x04];
    float field_14;
    float field_18;
    float (*vf)(float, float, float);
    char pad20[0x04];
    int field_24;
};

extern "C" void fn_8019CCF8(Foo* self, float f) {
    self->field_0C = self->vf(self->field_14, self->field_18, f);
    if (self->field_24 & 1) {
        fn_8019D618(self);
    }
}
