#pragma force_active on
#pragma opt_propagation off

extern "C" const float lbl_27_rodata_1F70[3];
extern "C" unsigned char lbl_27_data_2E3AC[0x44];

struct Object {
    void* vtable;
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
    unsigned char field7;
    int field8;
    float fieldC;
    float field10;
    float field14;
    float field18;
    float field1C;
    float field20;
    int field24;
};

extern "C" void fn_27_15CFE0(Object* self) {
    const float* constants = lbl_27_rodata_1F70;
    float c = constants[2];
    float b = constants[1];
    float a = constants[0];

    self->field4 = 0;
    self->field5 |= 0x80;
    self->field6 = 0;
    self->vtable = lbl_27_data_2E3AC;
    self->field8 = -1;
    self->fieldC = a;
    self->field10 = a;
    self->field14 = b;
    self->field18 = b;
    self->field1C = b;
    self->field20 = c;
    self->field24 = -1;
}
