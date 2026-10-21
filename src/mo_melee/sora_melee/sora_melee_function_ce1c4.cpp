#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int value : 8;
    unsigned int rest : 24;
};

extern "C" void fn_27_CE1C4(Data* self, unsigned int value) {
    self->value = value;
}
