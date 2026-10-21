#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int value : 10;
    unsigned int rest : 22;
};

extern "C" void fn_27_1A3784(Data* self, unsigned int value) {
    self->value = value;
}
