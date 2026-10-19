#pragma force_active on
struct Object {
    unsigned int unused[2];
    unsigned int field8;
    unsigned int fieldC;
    unsigned int field10;
};

extern "C" void fn_41_C3FC(Object* self, unsigned int value) {
    self->field10 = value;
    self->fieldC = value;
    self->field8 = value;
}
