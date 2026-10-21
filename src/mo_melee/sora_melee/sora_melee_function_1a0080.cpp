#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 2;
    unsigned int value : 2;
    unsigned int : 28;
};

extern "C" void fn_27_1A0080(Data* self, unsigned int value) {
    self->value = value;
}
