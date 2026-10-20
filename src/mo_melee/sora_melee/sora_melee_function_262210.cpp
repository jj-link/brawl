#pragma force_active on
extern "C" unsigned char lbl_27_data_54C18[0x20];

struct Object {
    void* vtable;
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0C;
};

extern "C" Object* fn_27_262210(Object* self) {
    self->field_0C = 0;
    self->vtable = lbl_27_data_54C18;
    self->field_08 = 0;
    self->field_04 = 0;
    return self;
}
