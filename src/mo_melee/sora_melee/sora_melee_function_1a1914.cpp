#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value : 6;
    unsigned int unused : 26;
};

extern "C" void fn_27_1A1914(Data* self, unsigned int value) {
    self->value = value;
}
