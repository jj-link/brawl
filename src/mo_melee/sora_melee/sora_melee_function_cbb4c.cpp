#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int flags : 4;
    unsigned int rest : 28;
};

extern "C" void fn_27_CBB4C(Data* self, unsigned int value) {
    self->flags = value;
}
