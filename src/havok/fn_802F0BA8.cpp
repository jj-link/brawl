#pragma force_active on
#pragma opt_propagation off

extern "C" const float lbl_805A44F8;
extern "C" const float lbl_805A44FC;
extern "C" const float lbl_805A4500;
extern "C" unsigned char lbl_80488630[0x40];

struct Obj {
    void* vtable;
    unsigned char field4;
    unsigned char field5;
    short field6;
    int field8;
    int fieldC;
    float field10;
    float field14;
    float field18;
    float field1C;
    float field20;
    int field24;
};

extern "C" void fn_802F0BA8(Obj* self, int arg1) {
    self->field6 = 1;
    self->vtable = lbl_80488630;
    self->field8 = arg1;
    self->field10 = lbl_805A44F8;
    self->field14 = lbl_805A44F8;
    self->field1C = lbl_805A44FC;
    self->field20 = lbl_805A4500;
    self->field24 = 0;
    self->fieldC = 1;
}
