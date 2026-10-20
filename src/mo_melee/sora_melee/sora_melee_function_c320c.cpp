#pragma force_active on
struct Unknown {
    unsigned char field_00[12];
    int field_0C;
    int field_10;
    unsigned char field_14;
};

extern "C" void fn_27_C320C(Unknown* self)
{
    self->field_0C = -1;
    self->field_14 = 0;
    self->field_10 = 12;
}
