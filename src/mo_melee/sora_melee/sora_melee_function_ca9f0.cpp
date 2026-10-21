#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int value : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_CA9F0(Data* self, unsigned int value) {
    self->value = value;
}
