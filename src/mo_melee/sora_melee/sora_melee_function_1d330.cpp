#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int high : 6;
    unsigned int value : 6;
    unsigned int low : 20;
};

extern "C" void fn_27_1D330(Data* self, unsigned int value) {
    self->value = value;
}
