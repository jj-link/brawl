#pragma force_active on
struct Data {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int : 8;
    unsigned int field : 4;
    unsigned int : 20;
};

extern "C" void fn_27_1A153C(Data* self, unsigned int value) {
    self->field = value;
}
