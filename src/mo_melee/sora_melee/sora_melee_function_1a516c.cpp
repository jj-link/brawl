#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 10;
    unsigned int field : 5;
    unsigned int : 17;
};

extern "C" void fn_27_1A516C(Data* self, unsigned int value) {
    self->field = value;
}
