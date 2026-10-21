#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int upper : 6;
    unsigned int field : 6;
    unsigned int lower : 20;
};

extern "C" void fn_27_CF1D4(Data* self, unsigned int value) {
    self->field = value;
}
