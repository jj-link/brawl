#pragma force_active on
extern float lbl_8059E8E0;
extern "C" void fn_8019D618(void*);

struct Foo {
    char pad0[0x0C];
    float field_0C;
    float field_10;
    float field_14;
    float field_18;
    float (*vf)(float, float, float);
    char pad20[0x04];
    int field_24;
};

extern "C" void fn_8019CD68(Foo* self) {
    self->field_0C = self->vf(self->field_14, self->field_18, self->field_0C + self->field_10 * lbl_8059E8E0);
    if (self->field_24 & 1) {
        fn_8019D618(self);
    }
}
