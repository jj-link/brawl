#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value : 7;
    unsigned int rest : 25;
};

extern "C" void fn_27_D0E64(Data* self, unsigned int value) {
    self->value = value;
}
